#pragma once
#pragma comment(lib, "log4cpp.lib")

#include <log4cpp\Category.hh>
#include <log4cpp\PropertyConfigurator.hh>

#include "ModbusSlave.h"
#include <iomanip> 

#using <System.dll>


namespace Server {

	using namespace System;
	using namespace System::Collections;
	using namespace System::ComponentModel;	
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Runtime::InteropServices;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			std::string initFileName = "log4cpp.properties";
			log4cpp::PropertyConfigurator::configure(initFileName);
			logger.setPriority(log4cpp::Priority::DEBUG);

			modbus = gcnew ModbusSlave();
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
			Marshal::FreeHGlobal(initialStringPtr);
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBoxComPort;
	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
	private: System::IO::Ports::SerialPort^  serialPort;
			 IntPtr initialStringPtr;
			 log4cpp::Category& logger = log4cpp::Category::getRoot();
			 ModbusSlave^ modbus;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxComPort = (gcnew System::Windows::Forms::ComboBox());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(12, 31);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(362, 274);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"COM-порт";
			// 
			// comboBoxComPort
			// 
			this->comboBoxComPort->FormattingEnabled = true;
			this->comboBoxComPort->Location = System::Drawing::Point(99, 4);
			this->comboBoxComPort->Name = L"comboBoxComPort";
			this->comboBoxComPort->Size = System::Drawing::Size(121, 21);
			this->comboBoxComPort->TabIndex = 2;
			this->comboBoxComPort->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxComPort_SelectedIndexChanged);
			// 
			// serialPort
			// 
			this->serialPort->PortName = L"COM10";
			this->serialPort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MainForm::serialPort_DataReceived);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 317);
			this->Controls->Add(this->comboBoxComPort);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"MainForm";
			this->Text = L"Сервер COM-порт";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->comboBoxComPort->Items->AddRange(FindCOMPortName());
			changeLogText();
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
				logger.info(StringToChar("Open serialPort " + comboBox->SelectedItem->ToString()));
				changeLogText();
			}
			catch(...){
				MessageBox::Show("Can't open" + comboBox->SelectedItem->ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		public: System::Void changeLogText(){
			this->logger.getAppender()->close();
			this->richTextBox1->LoadFile(gcnew String(this->logger.getAppender()->getName().c_str()) + ".log", RichTextBoxStreamType::PlainText);
			this->richTextBox1->SelectionStart = this->richTextBox1->Text->Length;
			this->richTextBox1->Focus();
			this->logger.getAppender()->reopen();
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
		private: const char* StringToChar(String^ string){
			initialStringPtr = Marshal::StringToHGlobalAnsi(string);
			char* converted = static_cast<char*>(initialStringPtr.ToPointer());
			return converted;
		}
		private: System::Void serialPort_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
			if (this->InvokeRequired){
				SerialDataReceivedEventHandler^ handler = gcnew SerialDataReceivedEventHandler(this, &MainForm::serialPort_DataReceived);
				this->Invoke(handler, sender, e);
			}
			else{
				SerialPort^ sp = (SerialPort^)sender;

				array< Byte >^ byteArrayInput = gcnew array<Byte>(sp->BytesToRead);
				sp->Read(byteArrayInput, 0, byteArrayInput->Length);
				std::stringstream ssInput;
				for (int i = 0; i < byteArrayInput->Length; i++){
					ssInput << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << (int)byteArrayInput[i] << " ";
				}
				String^ input = gcnew String(ssInput.str().c_str());
				logger.info(StringToChar("Get data: " + input)); 

				array< Byte >^ byteArrayOutput;
				__int16 first = 0;
				__int16 count = 0;
				switch (byteArrayInput[0])
				{
				case 1:
					first = (((__int16)(byteArrayInput[1])) << 8) | byteArrayInput[2];
					count = (((__int16)(byteArrayInput[3])) << 8) | byteArrayInput[4];
					byteArrayOutput = modbus->ReadCoilStatus(first, count);
					break;
				case 2:
					first = (((__int16)(byteArrayInput[1])) << 8) | byteArrayInput[2];
					count = (((__int16)(byteArrayInput[3])) << 8) | byteArrayInput[4];
					byteArrayOutput = modbus->ReadDiscreteInputs(first, count);
					break;
				case 3:
					first = (((__int16)(byteArrayInput[1])) << 8) | byteArrayInput[2];
					count = (((__int16)(byteArrayInput[3])) << 8) | byteArrayInput[4];
					byteArrayOutput = modbus->ReadHoldingRegisters(first, count);
					break;
				case 4:
					first = (((__int16)(byteArrayInput[1])) << 8) | byteArrayInput[2];
					count = (((__int16)(byteArrayInput[3])) << 8) | byteArrayInput[4];
					byteArrayOutput = modbus->ReadInputRegisters(first, count);
					break;
				case 8:
					byteArrayOutput = modbus->Diagnostic();
					break;
				default:
					break;
				}

				sp->Write(byteArrayOutput, 0, byteArrayOutput->Length);
				std::stringstream ssOutput;
				ssOutput << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << (int)byteArrayOutput[0] << " ";
				for (int i = 1; i < byteArrayOutput->Length; i++){
					if (byteArrayOutput[0] == 8)
						ssOutput << byteArrayOutput[i];
					else ssOutput << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << (int)byteArrayOutput[i] << " ";
				}
				String^ output = gcnew String(ssOutput.str().c_str());
				logger.info(StringToChar("Sent data: " + output));

				changeLogText();
			}
		}
	};
}
