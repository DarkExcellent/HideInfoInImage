#include "StdAfx.h"
#include "Form1.h"


namespace HideInformationInImage {
	void Form1::SetImage(String^ imgFileName)
	{
		picImage->Image = gcnew Bitmap(imgFileName);
		picImage->SizeMode = PictureBoxSizeMode::StretchImage; // чтобы картинка выводилась по размеру PictureBox
		int index = imgFileName->LastIndexOf("\\")+1;
		if(index > 0){imgFileName = imgFileName->Substring(index);}
		label2->Text = "Image Selected ("+imgFileName+")";
	}
	String^ Form1::GetFileName(String^ filter)
	{
		OpenFileDialog ^ dlg = gcnew OpenFileDialog();
		dlg->Multiselect = false;
		//dlg->Title = "Select image";
		if(filter->Length > 0){dlg->Filter = filter;}
		if(dlg->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
		{
			return dlg->FileName;
		}else
		{
			return nullptr;
		}
	
	}
	BinaryReader^ Form1::GetMessageStream()
	{
		BinaryReader^ bText;
		if(rdoMessageText->Checked)
		{
			String^ LOL = txtMessageText->Text;
			array<byte>^ utfBytes = Encoding::UTF8->GetBytes(LOL);
			array<byte>^ messageBytes = Encoding::Convert(Encoding::UTF8, Encoding::GetEncoding("windows-1251"), utfBytes);
			Stream^ rText = gcnew MemoryStream(messageBytes);
			bText = gcnew BinaryReader(rText, Encoding::ASCII);
			messageBytes = nullptr;
			rText = nullptr;
		}else
		{
			FileStream^ rText = gcnew System::IO::FileStream(txtMessageFile->Text, System::IO::FileMode::Open, System::IO::FileAccess::Read); //открываем поток
			bText = gcnew BinaryReader(rText, Encoding::GetEncoding("windows-1251"));
		}
		return bText;
	}
	BinaryReader^ Form1::GetKeyStream ()
	{
		BinaryReader^ bKey;
		array<byte>^ keyBytes = UnicodeEncoding::ASCII->GetBytes(txtKey->Text);
		Stream^ rKey = gcnew MemoryStream(keyBytes);
		bKey = gcnew BinaryReader(rKey, Encoding::ASCII);
		keyBytes = nullptr;
		rKey = nullptr;
		return bKey;
	}
	BitArray^ Form1::ByteToBit(byte src) 
	{
		BitArray^ bitArray = gcnew BitArray(8);
		bool st = false;
		for (int i = 0; i < 8; i++)
		{
			if ((src >> i & 1) == 1) 
			{
				st = true;
			} else st = false;
			bitArray[i] = st;
		}
		return bitArray;
	}
	BitArray^ Form1::IntToBit(int src) 
	{
		BitArray^ bitArray = gcnew BitArray(32);
		bool st = false;
		for (int i = 0; i < 32; i++)
		{
			if ((src >> i & 1) == 1) 
			{
				st = true;
			} else st = false;
			bitArray[i] = st;
		}
		return bitArray;
	}
	byte Form1::BitToByte(BitArray^ scr) 
	{
		byte num = 0;
		for (int i = 0; i < scr->Count; i++)
			if (scr[i] == true)
				num += (byte)Math::Pow(2, i);
		return num;
	}
	int Form1::BitToInt(BitArray^ scr) 
	{
		int num = 0;
		for (int i = 0; i < scr->Count; i++)
			if (scr[i] == true)
				num += (int)Math::Pow(2, i);
		return num;
	}

	BitArray^ Form1::ByteCrypt(BitArray^ message, BitArray^ key)
	{
		for(int i = 0; i < 8; i++)
		{
			if(message[i] == 1 && key[i] == 1){message[i] = 0;}
			else if(message[i] == 0 && key[i] == 0){message[i] = 0;}
			else if(message[i] == 1 && key[i] == 0){message[i] = 1;}
			else if(message[i] == 0 && key[i] == 1){message[i] = 1;}
		}
		return message;
	}
	BitArray^ Form1::ByteUncrypt(BitArray^ message, BitArray^ key)
	{
		for(int i = 0,j = 7; i < 8; i++,j--)
		{
			if((message[i] == 1 && key[j] == 1) || (message[i] == 0 && key[j] == 0))
			{message[i] = 0;}
			if((message[i] == 1 && key[j] == 0) || (message[i] == 0 && key[j] == 1))
			{message[i] = 1;}
		}
		return message;
	}
	System::Void Form1::btnChooseImage_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//dPic.Filter = "Файлы изображений (*.bmp)|*.bmp|Все файлы (*.*)|*.*";
		String^ imgFileName = GetFileName("Bitmaps (*.bmp)|*.bmp|Joint Photographic Experts Group (*.jpg)|*.jpg|Portable Network Graphics (*.png) | *.png");
		if(imgFileName == nullptr)
		{
			return;
		}
		if(imgFileName->Length != NULL)
		{
			txtImageFile->Text = imgFileName;
			SetImage(imgFileName);
		}
		btnHide->Enabled = true;
		btnExtract->Enabled = true;
		button2->Enabled = true;
	}
	System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	System::Void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		BinaryReader^ binText = GetMessageStream();
		List<byte> bList = gcnew List<byte>();
		while (binText->PeekChar() != -1) 
		{ //считали весь текстовый файл для шифрования в лист байт
			bList.Add(binText->ReadByte());
		}
		int CountText = bList.Count; // в CountText - количество в байтах текста, который нужно закодировать
		textBox2->Text = Convert::ToString(CountText);
	}
	System::Void Form1::btnMessage_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ fileName = GetFileName("Text files (*.txt)|*.txt");//(String::Empty);
		if(fileName != nullptr)
		{
			txtMessageFile->Text = fileName;
			rdoMessageFile->Checked = true;
		}
	}
	System::Void Form1::btnHide_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		btnHide->Enabled = false;
		BinaryReader^ binText = GetMessageStream();
		if(binText == nullptr)
		{
			btnHide->Enabled = true;
			return;
		}
		BinaryReader^ binKey = GetKeyStream();
		int BytesStep = Convert::ToInt32(numStep->Value);
		List<byte> bList = gcnew List<byte>();
		List<byte> bKey = gcnew List<byte>();
		//считали весь текстовый файл для шифрования в лист байт
		while (binText->PeekChar() != -1) 
		{ 
			bList.Add(binText->ReadByte());
		}
		//считали ключь в лист байт
		while(binKey->PeekChar() != -1)
		{
			bKey.Add(binKey->ReadByte());
		}
		int CountText = bList.Count; // Количество текста в байтах
		int KeySize = bKey.Count; // Размер ключа в байтах
		Bitmap^ bitmap = (Bitmap^)picImage->Image; //экземпляр картинки в которую будем прятать сообщение
		//listBox1->Items->Add("Количество текста :"+ CountText);
		//listBox1->Items->Add("Размер изображения :"+ (bitmap->Width * bitmap->Height));
		//listBox1->Items->Add("Записали бит: "+(CountText * 8 * BytesStep + 32 * BytesStep));
		// проверка на наличие ключа
		if(KeySize <= 0)
		{
			MessageBox::Show("You must to input key!", "Key error", MessageBoxButtons::OK);
			btnHide->Enabled = true;
			return;
		}
		// проверка на наличие текста
		if(CountText == 0)
		{
			MessageBox::Show("You did not input text, or chose empty txt file\nInput in field text or choose another txt file","Text error", MessageBoxButtons::OK);
			btnHide->Enabled = true;
			return;
		}
		// проверяем, поместится ли текст в переменную
		if(CountText > 2147483646)
		{
			MessageBox::Show("Text can not be more long 2 147 483 647 symbols", "Text error", MessageBoxButtons::OK);
			btnHide->Enabled = true;
			return;
		}
		// проверяем поместится ли текст в изображение
		if ((CountText * 8 * BytesStep + 32 * BytesStep + BytesStep) > (bitmap->Width * bitmap->Height))
		{
			MessageBox::Show("Chosen image is little for this text\nChoose another image or reduce step", "Error image size", MessageBoxButtons::OK);
			btnHide->Enabled = true;
			return;
		}
		int rgb_; 
		if(radioButton1->Checked == true){rgb_ = 1;}
		if(radioButton2->Checked == true){rgb_ = 2;}
		if(radioButton3->Checked == true){rgb_ = 3;}
		// Запись количества текста в первые 32 пикселя
		int Symbol = bList.Count; // Количества текса в байтах
		BitArray^ ArrBeginSymbol = IntToBit(Symbol);
		Color curColor;
		byte nrgb;
		Color nColor;
		int last_i = 0;
		int Pix = BytesStep;
		int tmp2 = 0;
		for(int i = 0; i < 32; i++)
		{
			BitArray^ tempArray;
			curColor = bitmap->GetPixel(Pix, tmp2);
			if(rgb_ == 1){tempArray = ByteToBit(curColor.R);}
			if(rgb_ == 2){tempArray = ByteToBit(curColor.G);}
			if(rgb_ == 3){tempArray = ByteToBit(curColor.B);}
			tempArray[0] = ArrBeginSymbol[i];
			nrgb = BitToByte(tempArray);
			if(rgb_ == 1){nColor = Color::FromArgb(nrgb, curColor.G, curColor.B);}
			if(rgb_ == 2){nColor = Color::FromArgb(curColor.R, nrgb, curColor.B);}
			if(rgb_ == 3){nColor = Color::FromArgb(curColor.R, curColor.G, nrgb);}
			bitmap->SetPixel(Pix, tmp2, nColor);
			tempArray = nullptr;
			Pix = Pix + BytesStep;
			if(Pix >= bitmap->Width)
			{
				tmp2++;
				Pix = BytesStep;
			}
		}
		//ArrBeginSymbol = nullptr;
		/////////////////////////////////////////
		// запись самого текста
		int index = 0;
		bool st = false;
		int j = tmp2; int i = Pix;
		while (st == false)
		{
			BitArray^ messageArray = ByteToBit(bList[index]);
			for(int step = 0; step < KeySize; step++)
			{
				BitArray^ keyArray = ByteToBit(bKey[step]);
				messageArray = ByteCrypt(messageArray,keyArray);
			}
			for(int k = 0; k < 8; k++)
			{
				Color pixelColor = bitmap->GetPixel(i, j);
				BitArray^ colorArray; 
				if(rgb_ == 1){colorArray = ByteToBit(pixelColor.R);}
				if(rgb_ == 2){colorArray = ByteToBit(pixelColor.G);}
				if(rgb_ == 3){colorArray = ByteToBit(pixelColor.B);}
				colorArray[0] = messageArray[k];
				byte newR = BitToByte(colorArray);
				Color newColor; 
				if(rgb_ == 1){newColor = Color::FromArgb(newR, pixelColor.G, pixelColor.B);}
				if(rgb_ == 2){newColor = Color::FromArgb(pixelColor.R, newR, pixelColor.B);}
				if(rgb_ == 3){newColor = Color::FromArgb(pixelColor.R, pixelColor.G, newR);}
				bitmap->SetPixel(i, j, newColor);
				i+= BytesStep;
				if(i >= bitmap->Width)
				{
					j++;
					i = BytesStep;
				}
			}
			index++;
			if (index == bList.Count) 
			{
				st = true;
			}
		}

		picImage->Image = bitmap;
		btnHide->Enabled = true;
		btnSaveBitmap->Enabled = true;
		label6->Text = "Hide text was successful!"; 
		label6->Visible = true;

		// конец записи текста
		/////////////////////////////////////////////////////////
	}
	System::Void Form1::btnSaveBitmap_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		txtKey->Clear();
		txtMessageText->Clear();
		SaveFileDialog^ dlg = gcnew SaveFileDialog();
		dlg->Filter = "Bitmaps (*.bmp)|*.bmp|Joint Photographic Experts Group (*.jpg)|*.jpg|Portable Network Graphics (*.png) | *.png";
		Image^ img = gcnew Bitmap(picImage->Image);
		System::Drawing::Imaging::ImageFormat^ format;
		if( dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK )
		{
			format = System::Drawing::Imaging::ImageFormat::Bmp;
		}
		if(dlg->FileName == txtImageFile->Text)
		{
			MessageBox::Show("Choose another name of image","Error image name",MessageBoxButtons::OK);
			return;
		}
		img->Save(dlg->FileName, format);

		//close bitmap file
		this->SuspendLayout();
		picImage->Image = nullptr;
		txtImageFile->Text = String::Empty;
		this->ResumeLayout();
		btnSaveBitmap->Enabled = false;
		btnHide->Enabled = false;
		btnExtract->Enabled = false;
		label6->Visible = false;
		numStep->Value = 1;
	}
	System::Void Form1::btnExtract_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		txtExtractedMsgText->Clear();
		int BytesStep = Convert::ToInt32(numStep->Value);
		BinaryReader^ binKey = GetKeyStream();
		List<byte> bKey = gcnew List<byte>();
		//считали ключь в лист байт
		while(binKey->PeekChar() != -1)
		{
			bKey.Add(binKey->ReadByte());
		}
		int KeySize = bKey.Count; // Размер ключа в байтах
		// проверка на наличие ключа
		if(KeySize <= 0)
		{
			MessageBox::Show("You must input key!", "Error key", MessageBoxButtons::OK);
			return;
		}
		Bitmap^ bitmap = (Bitmap^)picImage->Image;
		int rgb_;
		if(radioButton1->Checked == true){rgb_ = 1;}
		if(radioButton2->Checked == true){rgb_ = 2;}
		if(radioButton3->Checked == true){rgb_ = 3;}
		// получение количества текста
		//int last_i = 700;
		int Pix = BytesStep;
		int symbol;
		Color curColor = bitmap->GetPixel(0, 0);
		int tmp2 = 0;
		BitArray^ messageArray = IntToBit(Pix);//получаем массив "Количество символов"
		for(int i = 0; i < 32; i++)
		{
			curColor = bitmap->GetPixel(Pix, tmp2);
			BitArray^ tempArray;
			if(rgb_ == 1){tempArray = ByteToBit(curColor.R);}
			if(rgb_ == 2){tempArray = ByteToBit(curColor.G);}
			if(rgb_ == 3){tempArray = ByteToBit(curColor.B);}
			messageArray[i] = tempArray[0];
			Pix = Pix + BytesStep;
			if(Pix >= bitmap->Width)
			{
				tmp2++;
				Pix = BytesStep;
			}
		}
		symbol = BitToInt(messageArray); //получаем байт символа, записанного в первых пикселях
		if(symbol <= 0)
		{
			MessageBox::Show("Text was not detected","Error text",MessageBoxButtons::OK);
			return;
		}
		if(symbol >= (bitmap->Height * bitmap->Width))
		{
			MessageBox::Show("Text was not detected","Error text",MessageBoxButtons::OK);
			return;
		}
		// получение самого текста
		array<byte>^ message = gcnew array<byte>(symbol);
		int index = 0;
		bool st = false;
		int j = tmp2; int i = Pix;
		while (st == false)
		{
			Color pixelColor = bitmap->GetPixel(0, 0);
			BitArray^ messageArray;
			if(rgb_ == 1){messageArray = ByteToBit(pixelColor.R);}
			if(rgb_ == 2){messageArray = ByteToBit(pixelColor.G);}
			if(rgb_ == 3){messageArray = ByteToBit(pixelColor.B);}
			byte temp;
			for(int k = 0; k < 8; k++)
			{
				Color pixelColor = bitmap->GetPixel(i, j);
				BitArray^ colorArray;
				if(rgb_ == 1){colorArray = ByteToBit(pixelColor.R);}
				if(rgb_ == 2){colorArray = ByteToBit(pixelColor.G);}
				if(rgb_ == 3){colorArray = ByteToBit(pixelColor.B);}
				messageArray[k] = colorArray[0];
				i+=BytesStep;
				if(i >= bitmap->Width)
				{
					j++;
					i = BytesStep;
				}
			}
			for(int step = 0; step < KeySize; step++)
			{
				BitArray^ keyArray = ByteToBit(bKey[step]);
				messageArray = ByteCrypt(messageArray,keyArray);
			}
			temp = BitToByte(messageArray);
			message[index] = temp;
			index++;
			if (index == message->Length) 
			{
				st = true;
			}
		} 
		array<byte>^ messageBytes = Encoding::Convert(Encoding::GetEncoding("windows-1251"), Encoding::UTF8, message);
		String^ str = Encoding::UTF8->GetString(messageBytes);
		txtExtractedMsgText->Text = Convert::ToString(str);
		btnExtractedMsgFile->Enabled = true;
	}
	System::Void Form1::btnExtractedMsgFile_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		SaveFileDialog^ dlg = gcnew SaveFileDialog();
		dlg->Filter = "txt files|*.txt";
		if(dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			File::WriteAllText(dlg->FileName,txtExtractedMsgText->Text,Encoding::Unicode);
		}
	}

}