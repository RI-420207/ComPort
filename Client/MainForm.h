#pragma once

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
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tx;

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
	private: System::IO::Ports::SerialPort^  serialPort;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tx = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->rx = (gcnew System::Windows::Forms::Label());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->comboBoxComPort = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Отправить:";
			// 
			// tx
			// 
			this->tx->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tx->Location = System::Drawing::Point(12, 65);
			this->tx->Multiline = true;
			this->tx->Name = L"tx";
			this->tx->Size = System::Drawing::Size(260, 68);
			this->tx->TabIndex = 1;
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
			this->rx->AutoSize = true;
			this->rx->Location = System::Drawing::Point(11, 25);
			this->rx->Name = L"rx";
			this->rx->Size = System::Drawing::Size(0, 13);
			this->rx->TabIndex = 3;
			// 
			// buttonSend
			// 
			this->buttonSend->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonSend->Location = System::Drawing::Point(197, 139);
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
			this->splitContainer->Location = System::Drawing::Point(0, 0);
			this->splitContainer->Name = L"splitContainer";
			this->splitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->comboBoxComPort);
			this->splitContainer->Panel1->Controls->Add(this->label3);
			this->splitContainer->Panel1->Controls->Add(this->tx);
			this->splitContainer->Panel1->Controls->Add(this->buttonSend);
			this->splitContainer->Panel1->Controls->Add(this->label1);
			this->splitContainer->Panel1MinSize = 125;
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->label2);
			this->splitContainer->Panel2->Controls->Add(this->rx);
			this->splitContainer->Panel2MinSize = 75;
			this->splitContainer->Size = System::Drawing::Size(284, 261);
			this->splitContainer->SplitterDistance = 165;
			this->splitContainer->TabIndex = 5;
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
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->comboBoxComPort->Items->AddRange(FindCOMPortName());
			this->comboBoxComPort->SelectedIndex = 0;
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
			this->serialPort->WriteLine(this->tx->Text);
		}
		private: System::Void serialPort_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
			if (this->InvokeRequired){
				SerialDataReceivedEventHandler^ handler = gcnew SerialDataReceivedEventHandler(this, &MainForm::serialPort_DataReceived);
				this->Invoke(handler, sender, e);
			}
			else{
				SerialPort^ sp = (SerialPort^)sender;
				this->rx->Text = sp->ReadExisting();
			}
		}
	};
}
