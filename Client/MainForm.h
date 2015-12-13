#pragma once

#include <sstream>
#include <iomanip>

#include "ModbusMaster.h"

#using <System.dll>

namespace Client {

	using namespace System;
	using namespace System::Collections;
	using namespace System::ComponentModel;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Windows::Forms;
	using namespace std;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			modbus = gcnew ModbusImplMaster();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			delete modbus;
		}



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  rx;
	private: System::Windows::Forms::Button^  buttonSend;
	private: System::Windows::Forms::SplitContainer^  splitContainer;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>

	private: System::Windows::Forms::ComboBox^  comboBoxComPort;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBoxFunction;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownFirst;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownCount;

	private: System::Windows::Forms::Label^  label5;
	private: System::IO::Ports::SerialPort^  serialPort;
	private: ModbusImplMaster^ modbus;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->rx = (gcnew System::Windows::Forms::Label());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->comboBoxFunction = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxComPort = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->numericUpDownFirst = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownFirst))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCount))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Принято:";
			// 
			// rx
			// 
			this->rx->AutoEllipsis = true;
			this->rx->AutoSize = true;
			this->rx->Location = System::Drawing::Point(11, 25);
			this->rx->MaximumSize = System::Drawing::Size(280, 0);
			this->rx->Name = L"rx";
			this->rx->Size = System::Drawing::Size(0, 13);
			this->rx->TabIndex = 3;
			// 
			// buttonSend
			// 
			this->buttonSend->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonSend->Location = System::Drawing::Point(206, 28);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(75, 23);
			this->buttonSend->TabIndex = 4;
			this->buttonSend->Text = L"Отправить";
			this->buttonSend->UseVisualStyleBackColor = true;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MainForm::buttonSend_Click);
			// 
			// splitContainer
			// 
			this->splitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer->Location = System::Drawing::Point(0, 0);
			this->splitContainer->Name = L"splitContainer";
			this->splitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->buttonSend);
			this->splitContainer->Panel1->Controls->Add(this->comboBoxFunction);
			this->splitContainer->Panel1->Controls->Add(this->label1);
			this->splitContainer->Panel1->Controls->Add(this->comboBoxComPort);
			this->splitContainer->Panel1->Controls->Add(this->label3);
			this->splitContainer->Panel1->Controls->Add(this->splitContainer1);
			this->splitContainer->Panel1MinSize = 50;
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->label2);
			this->splitContainer->Panel2->Controls->Add(this->rx);
			this->splitContainer->Panel2MinSize = 75;
			this->splitContainer->Size = System::Drawing::Size(284, 261);
			this->splitContainer->SplitterDistance = 56;
			this->splitContainer->TabIndex = 5;
			// 
			// comboBoxFunction
			// 
			this->comboBoxFunction->FormattingEnabled = true;
			this->comboBoxFunction->Location = System::Drawing::Point(77, 33);
			this->comboBoxFunction->Name = L"comboBoxFunction";
			this->comboBoxFunction->Size = System::Drawing::Size(121, 21);
			this->comboBoxFunction->TabIndex = 8;
			this->comboBoxFunction->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxFunction_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Функция";
			// 
			// comboBoxComPort
			// 
			this->comboBoxComPort->FormattingEnabled = true;
			this->comboBoxComPort->Location = System::Drawing::Point(77, 5);
			this->comboBoxComPort->Name = L"comboBoxComPort";
			this->comboBoxComPort->Size = System::Drawing::Size(121, 21);
			this->comboBoxComPort->TabIndex = 6;
			this->comboBoxComPort->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxComPort_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"COM-порт";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->Location = System::Drawing::Point(17, 57);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->numericUpDownFirst);
			this->splitContainer1->Panel1->Controls->Add(this->label4);
			this->splitContainer1->Panel1MinSize = 125;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->numericUpDownCount);
			this->splitContainer1->Panel2->Controls->Add(this->label5);
			this->splitContainer1->Panel2MinSize = 125;
			this->splitContainer1->Size = System::Drawing::Size(255, 101);
			this->splitContainer1->SplitterDistance = 126;
			this->splitContainer1->TabIndex = 9;
			// 
			// numericUpDownFirst
			// 
			this->numericUpDownFirst->Location = System::Drawing::Point(7, 21);
			this->numericUpDownFirst->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
			this->numericUpDownFirst->Name = L"numericUpDownFirst";
			this->numericUpDownFirst->Size = System::Drawing::Size(117, 20);
			this->numericUpDownFirst->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 4);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Первый элемент";
			// 
			// numericUpDownCount
			// 
			this->numericUpDownCount->Location = System::Drawing::Point(7, 20);
			this->numericUpDownCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
			this->numericUpDownCount->Name = L"numericUpDownCount";
			this->numericUpDownCount->Size = System::Drawing::Size(114, 20);
			this->numericUpDownCount->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(4, 4);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Количество";
			// 
			// serialPort
			// 
			this->serialPort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MainForm::serialPort_DataReceived);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->splitContainer);
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"MainForm";
			this->Text = L"Клиент для COM-порта";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->splitContainer->Panel1->ResumeLayout(false);
			this->splitContainer->Panel1->PerformLayout();
			this->splitContainer->Panel2->ResumeLayout(false);
			this->splitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->EndInit();
			this->splitContainer->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownFirst))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCount))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->comboBoxComPort->Items->AddRange(FindCOMPortName());

			this->comboBoxFunction->Items->Add("ReadCoilStatus");
			this->comboBoxFunction->Items->Add("ReadDiscreteInputs");
			this->comboBoxFunction->Items->Add("ReadHoldingRegisters");
			this->comboBoxFunction->Items->Add("ReadInputRegisters");
			this->comboBoxFunction->Items->Add("Diagnostic");
			this->comboBoxFunction->SelectedIndex = 0;
		}
		private: System::Void comboBoxComPort_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			ComboBox^ comboBox = (ComboBox^)(sender);
			if (this->serialPort->PortName->Equals(comboBox->SelectedItem->ToString())) return;
			try{
				this->serialPort->Close();
				this->serialPort->PortName = comboBox->SelectedItem->ToString();

				this->serialPort->BaudRate = 9600;
				this->serialPort->Parity = Parity::None;
				this->serialPort->StopBits = StopBits::One;
				this->serialPort->DataBits = 8;
				this->serialPort->Handshake = Handshake::None;
				this->serialPort->RtsEnable = true;

				this->serialPort->Encoding = gcnew System::Text::ASCIIEncoding();

				this->serialPort->Open();
			}
			catch (...){
				MessageBox::Show("Can't open" + comboBox->SelectedItem->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: array<Object^, 1>^  FindCOMPortName(){
			array<Object ^> ^arr = gcnew array<Object ^>(1);
			for each (String^ var in SerialPort::GetPortNames())
			{
				if (var->StartsWith("COM")) {
					if (arr[arr->Length - 1]){
						Array::Resize(arr, arr->Length + 1);
					}
					arr->SetValue(var, arr->Length - 1);
				}
			}
			return arr;
		}
		private: System::Void buttonSend_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!this->serialPort->IsOpen){
				MessageBox::Show("Can't write in a closed port", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			array<Byte>^ toWrite;
			switch (this->comboBoxFunction->SelectedIndex)
			{
			case 0:
				toWrite = modbus->ReadCoilStatus(Convert::ToInt16(this->numericUpDownFirst->Value), Convert::ToInt16(this->numericUpDownCount->Value));
				break;
			case 1:
				toWrite = modbus->ReadDiscreteInputs(Convert::ToInt16(this->numericUpDownFirst->Value), Convert::ToInt16(this->numericUpDownCount->Value));
				break;
			case 2:
				toWrite = modbus->ReadHoldingRegisters(Convert::ToInt16(this->numericUpDownFirst->Value), Convert::ToInt16(this->numericUpDownCount->Value));
				break;
			case 3:
				toWrite = modbus->ReadInputRegisters(Convert::ToInt16(this->numericUpDownFirst->Value), Convert::ToInt16(this->numericUpDownCount->Value));
				break;
			case 4:
				toWrite = modbus->Diagnostic();
				break;
			default:
				break;
			}

			this->serialPort->Write(toWrite, 0, toWrite->Length);
		}
		private: System::Void serialPort_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
			if (this->InvokeRequired){
				SerialDataReceivedEventHandler^ handler = gcnew SerialDataReceivedEventHandler(this, &MainForm::serialPort_DataReceived);
				this->Invoke(handler, sender, e);
			}
			else{
				SerialPort^ sp = (SerialPort^)sender;
				array< Byte >^ byteArray = gcnew array< Byte >(sp->BytesToRead);
				sp->Read(byteArray, 0, sp->BytesToRead);
				std::stringstream ss;
				ss << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << (int)byteArray[0] << " ";
				for (int i = 1; i < byteArray->Length; i++){
					if (byteArray[0] == 8)
						ss << byteArray[i];
					else
						ss << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << (int)byteArray[i] << " ";
				}
				this->rx->Text = gcnew String(ss.str().c_str());
			}
		}
	private: System::Void comboBoxFunction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		ComboBox^ sp = (ComboBox^)sender;
		if (sp->SelectedItem->ToString()->Equals("Diagnostic")){
			this->splitContainer1->Hide();
			this->splitContainer->SplitterDistance -= 70;
		}
		else {
			this->splitContainer1->Show();
			this->splitContainer->SplitterDistance += 70;
		}
	}
};
}
