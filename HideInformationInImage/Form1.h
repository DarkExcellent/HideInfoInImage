#pragma once
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <WinBase.h>

namespace HideInformationInImage {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Xml;
	using namespace System::Collections;
	using namespace System::Collections::Generic;

	//typedef unsigned char       BYTE;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnChooseImage;
	protected: 
	private: System::Windows::Forms::TextBox^  txtImageFile;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  picImage;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  btnMessage;
	private: System::Windows::Forms::TextBox^  txtMessageFile;
	private: System::Windows::Forms::TextBox^  txtMessageText;
	private: System::Windows::Forms::RadioButton^  rdoMessageText;
	private: System::Windows::Forms::RadioButton^  rdoMessageFile;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  btnHide;
	private: System::Windows::Forms::Button^  btnSaveBitmap;
	private: System::Windows::Forms::TextBox^  txtExtractedMsgText;
	private: System::Windows::Forms::Button^  btnExtract;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;

	private: System::Windows::Forms::Button^  btnExtractedMsgFile;
	private: System::Windows::Forms::TextBox^  txtKey;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numStep;
	private: System::Windows::Forms::Label^  label6;







	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnChooseImage = (gcnew System::Windows::Forms::Button());
			this->txtImageFile = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picImage = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->btnSaveBitmap = (gcnew System::Windows::Forms::Button());
			this->btnHide = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnMessage = (gcnew System::Windows::Forms::Button());
			this->txtMessageFile = (gcnew System::Windows::Forms::TextBox());
			this->txtMessageText = (gcnew System::Windows::Forms::TextBox());
			this->rdoMessageText = (gcnew System::Windows::Forms::RadioButton());
			this->rdoMessageFile = (gcnew System::Windows::Forms::RadioButton());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btnExtractedMsgFile = (gcnew System::Windows::Forms::Button());
			this->btnExtract = (gcnew System::Windows::Forms::Button());
			this->txtExtractedMsgText = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->txtKey = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numStep = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picImage))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numStep))->BeginInit();
			this->SuspendLayout();
			// 
			// btnChooseImage
			// 
			this->btnChooseImage->Location = System::Drawing::Point(264, 9);
			this->btnChooseImage->Name = L"btnChooseImage";
			this->btnChooseImage->Size = System::Drawing::Size(140, 25);
			this->btnChooseImage->TabIndex = 0;
			this->btnChooseImage->Text = L"Choice image";
			this->btnChooseImage->UseVisualStyleBackColor = true;
			this->btnChooseImage->Click += gcnew System::EventHandler(this, &Form1::btnChooseImage_Click);
			// 
			// txtImageFile
			// 
			this->txtImageFile->Location = System::Drawing::Point(52, 12);
			this->txtImageFile->Name = L"txtImageFile";
			this->txtImageFile->Size = System::Drawing::Size(206, 20);
			this->txtImageFile->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Image";
			// 
			// picImage
			// 
			this->picImage->Location = System::Drawing::Point(12, 38);
			this->picImage->Name = L"picImage";
			this->picImage->Size = System::Drawing::Size(392, 216);
			this->picImage->TabIndex = 3;
			this->picImage->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 257);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Image is not chose";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(410, 9);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(418, 461);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->btnSaveBitmap);
			this->tabPage1->Controls->Add(this->btnHide);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->btnMessage);
			this->tabPage1->Controls->Add(this->txtMessageFile);
			this->tabPage1->Controls->Add(this->txtMessageText);
			this->tabPage1->Controls->Add(this->rdoMessageText);
			this->tabPage1->Controls->Add(this->rdoMessageFile);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(410, 435);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Hide";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 226);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Text";
			this->label6->Visible = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(207, 261);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(177, 108);
			this->listBox1->TabIndex = 11;
			this->listBox1->Visible = false;
			// 
			// btnSaveBitmap
			// 
			this->btnSaveBitmap->Enabled = false;
			this->btnSaveBitmap->Location = System::Drawing::Point(100, 245);
			this->btnSaveBitmap->Name = L"btnSaveBitmap";
			this->btnSaveBitmap->Size = System::Drawing::Size(88, 40);
			this->btnSaveBitmap->TabIndex = 10;
			this->btnSaveBitmap->Text = L"Save image";
			this->btnSaveBitmap->UseVisualStyleBackColor = true;
			this->btnSaveBitmap->Click += gcnew System::EventHandler(this, &Form1::btnSaveBitmap_Click);
			// 
			// btnHide
			// 
			this->btnHide->Enabled = false;
			this->btnHide->Location = System::Drawing::Point(6, 245);
			this->btnHide->Name = L"btnHide";
			this->btnHide->Size = System::Drawing::Size(88, 40);
			this->btnHide->TabIndex = 9;
			this->btnHide->Text = L"Hide";
			this->btnHide->UseVisualStyleBackColor = true;
			this->btnHide->Click += gcnew System::EventHandler(this, &Form1::btnHide_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(25, 404);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(126, 21);
			this->textBox2->TabIndex = 8;
			this->textBox2->Visible = false;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(25, 375);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(117, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Поток байтов";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(148, 349);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(22, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 349);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 20);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Bytes";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// btnMessage
			// 
			this->btnMessage->Location = System::Drawing::Point(306, 34);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(98, 23);
			this->btnMessage->TabIndex = 4;
			this->btnMessage->Text = L"Choice file";
			this->btnMessage->UseVisualStyleBackColor = true;
			this->btnMessage->Click += gcnew System::EventHandler(this, &Form1::btnMessage_Click);
			// 
			// txtMessageFile
			// 
			this->txtMessageFile->Location = System::Drawing::Point(100, 36);
			this->txtMessageFile->Name = L"txtMessageFile";
			this->txtMessageFile->Size = System::Drawing::Size(200, 20);
			this->txtMessageFile->TabIndex = 3;
			// 
			// txtMessageText
			// 
			this->txtMessageText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtMessageText->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->txtMessageText->Location = System::Drawing::Point(6, 84);
			this->txtMessageText->Multiline = true;
			this->txtMessageText->Name = L"txtMessageText";
			this->txtMessageText->Size = System::Drawing::Size(398, 139);
			this->txtMessageText->TabIndex = 2;
			// 
			// rdoMessageText
			// 
			this->rdoMessageText->AutoSize = true;
			this->rdoMessageText->Checked = true;
			this->rdoMessageText->Location = System::Drawing::Point(6, 61);
			this->rdoMessageText->Name = L"rdoMessageText";
			this->rdoMessageText->Size = System::Drawing::Size(46, 17);
			this->rdoMessageText->TabIndex = 1;
			this->rdoMessageText->TabStop = true;
			this->rdoMessageText->Text = L"Text";
			this->rdoMessageText->UseVisualStyleBackColor = true;
			// 
			// rdoMessageFile
			// 
			this->rdoMessageFile->AutoSize = true;
			this->rdoMessageFile->Location = System::Drawing::Point(6, 38);
			this->rdoMessageFile->Name = L"rdoMessageFile";
			this->rdoMessageFile->Size = System::Drawing::Size(85, 17);
			this->rdoMessageFile->TabIndex = 0;
			this->rdoMessageFile->Text = L"Text from file";
			this->rdoMessageFile->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Transparent;
			this->tabPage2->Controls->Add(this->btnExtractedMsgFile);
			this->tabPage2->Controls->Add(this->btnExtract);
			this->tabPage2->Controls->Add(this->txtExtractedMsgText);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(410, 435);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Get";
			// 
			// btnExtractedMsgFile
			// 
			this->btnExtractedMsgFile->Enabled = false;
			this->btnExtractedMsgFile->Location = System::Drawing::Point(204, 143);
			this->btnExtractedMsgFile->Name = L"btnExtractedMsgFile";
			this->btnExtractedMsgFile->Size = System::Drawing::Size(183, 23);
			this->btnExtractedMsgFile->TabIndex = 3;
			this->btnExtractedMsgFile->Text = L"Save to txt";
			this->btnExtractedMsgFile->UseVisualStyleBackColor = true;
			this->btnExtractedMsgFile->Click += gcnew System::EventHandler(this, &Form1::btnExtractedMsgFile_Click);
			// 
			// btnExtract
			// 
			this->btnExtract->Enabled = false;
			this->btnExtract->Location = System::Drawing::Point(9, 143);
			this->btnExtract->Name = L"btnExtract";
			this->btnExtract->Size = System::Drawing::Size(189, 23);
			this->btnExtract->TabIndex = 2;
			this->btnExtract->Text = L"Get text";
			this->btnExtract->UseVisualStyleBackColor = true;
			this->btnExtract->Click += gcnew System::EventHandler(this, &Form1::btnExtract_Click);
			// 
			// txtExtractedMsgText
			// 
			this->txtExtractedMsgText->Location = System::Drawing::Point(9, 7);
			this->txtExtractedMsgText->Multiline = true;
			this->txtExtractedMsgText->Name = L"txtExtractedMsgText";
			this->txtExtractedMsgText->ReadOnly = true;
			this->txtExtractedMsgText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtExtractedMsgText->Size = System::Drawing::Size(378, 130);
			this->txtExtractedMsgText->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(12, 299);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(153, 86);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Choice color stream";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 65);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(46, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->Text = L"Blue";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(54, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"Green";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(6, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(45, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Red";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// txtKey
			// 
			this->txtKey->Location = System::Drawing::Point(52, 273);
			this->txtKey->Name = L"txtKey";
			this->txtKey->Size = System::Drawing::Size(352, 20);
			this->txtKey->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 276);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Key";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 393);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Step";
			// 
			// numStep
			// 
			this->numStep->Location = System::Drawing::Point(45, 391);
			this->numStep->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2147483646, 0, 0, 0});
			this->numStep->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numStep->Name = L"numStep";
			this->numStep->Size = System::Drawing::Size(120, 20);
			this->numStep->TabIndex = 11;
			this->numStep->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 488);
			this->Controls->Add(this->numStep);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtKey);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->picImage);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtImageFile);
			this->Controls->Add(this->btnChooseImage);
			this->Name = L"Form1";
			this->Text = L"Hide text into image";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picImage))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numStep))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void SetImage(String^ imgFileName);
	private: String^ GetFileName(String^ filter);
	private: BinaryReader^ GetMessageStream();
	private: BinaryReader^ GetKeyStream ();
	private: BitArray^ ByteToBit(byte src);
	private: BitArray^ IntToBit(int src);
	private: byte BitToByte(BitArray^ scr);
	private: int BitToInt(BitArray^ scr);
	private: BitArray^ ByteCrypt(BitArray^ message, BitArray^ key);
	private: BitArray^ ByteUncrypt(BitArray^ message, BitArray^ key);
	private: System::Void btnChooseImage_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnMessage_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnHide_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSaveBitmap_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnExtract_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnExtractedMsgFile_Click(System::Object^  sender, System::EventArgs^  e);
	};
}


