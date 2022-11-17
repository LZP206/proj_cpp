#include "workerManager.h"

workerManager::workerManager()
{
    this->m_workerNum =  0;
	this->m_workerArray = NULL;

	ifstream input_workerInfo;
	input_workerInfo.open(Filename, ios::in);
	// 1.文件不存在情况
	if (!input_workerInfo.is_open())
	{
		cout << "文件不存在，打开失败" << endl; 
		this->m_FileisEmpty = true; 
		input_workerInfo.close();
		return;
	}
	// 2.文件存在但内容为空
	else if ( input_workerInfo.eof() )   // (buffer = ifs.get()) != EOF
	{
		cout << "文件存在但内容为空" << endl;
		this->m_FileisEmpty = true; 
		input_workerInfo.close();
		return;  
	}
	// 3.文件存在且内容不为空
	else
	{		
		int temp_workerNum = getInfo_workerNum();
		cout << "已记录职员人数为: " << temp_workerNum << endl;
		this->m_workerNum = temp_workerNum;
		this->m_workerArray = new Worker * [this->m_workerNum];
		initial_workerArray();
		this->m_FileisEmpty = false;
	}
}


workerManager::~workerManager()
{
    if (this->m_workerArray != NULL)
	{
		delete[] this->m_workerArray;
		this->m_workerArray = NULL;
	}
}




// -----------------------------------------------------------------------




void workerManager::Show_Menu()
{
    cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}



void workerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
	// system("pause");
	exit(0);
}



void workerManager::addWorker()
{
	cout << "请输入新增员工人数" << endl;
	int temp_addWorkerNum = 0;
	cin >> temp_addWorkerNum;

	if (temp_addWorkerNum <= 0)
	{
		cout << "人数输入有误" << endl;
		return;
	}
	else
	{
		int new_WorkerNum = this->m_workerNum + temp_addWorkerNum;
		Worker ** newspace = new Worker *[new_WorkerNum];

		if (this->m_workerArray != NULL)
		{
			for (int i = 0; i < this->m_workerNum; i++)
			{
				newspace[i] = this->m_workerArray[i];
			}
		}

		for (int i = 0; i < temp_addWorkerNum; i++)
		{
			int temp_ID;
			string temp_Name;
			int temp_selectPosName;
			int temp_selectDeptName;
			cout << "******开始输入第" << i+1 << "个新员工的相关信息******" << endl;

			cout << "请输入员工姓名: " << endl;
			cin >> temp_Name;

			while (true)
			{
				cout << "请输入员工编号: " << endl;
				cin >> temp_ID;
				if (this->isexist_ID(temp_ID) == -1 ){break;}
				cout << "该员工编号已存在，请重新输入" << endl;
			}

			cout << "请选择员工所属部门: " << endl;
			cout << "101-技术部\t"
				 << "102-销售部\t"
				 << "103-法务部\t"
				 << "104-财务部\t"
				 << "105-人力部" << endl;
			cin >> temp_selectDeptName;

			cout << "请选择员工岗位: " << endl;
			cout << "1-总裁\t"
				 << "2-经理\t"
				 << "3-职员" << endl;
			cin >> temp_selectPosName;

			Worker * temp_worker = NULL;
			switch (temp_selectPosName)
			{
			case 1:
				temp_worker = new Boss(temp_ID, temp_Name, temp_selectDeptName);
				break;
			case 2:
				temp_worker = new Manager(temp_ID, temp_Name, temp_selectDeptName);
				break;
			case 3:
				temp_worker = new Employee(temp_ID, temp_Name, temp_selectDeptName);
				break;
			default:
				break;
			}
			newspace[this->m_workerNum + i] = temp_worker;
		}

		delete[] this->m_workerArray;
		this->m_workerArray = newspace;
		this->m_workerNum = new_WorkerNum;
		this->m_FileisEmpty = false;
		cout << "已成功添加" << temp_addWorkerNum << "位新员工" << endl;
	}

	this->saveInfo();
}



void workerManager::saveInfo()
{
	ofstream output_workerInfo;
	output_workerInfo.open(Filename, ios::out);

	for (int i = 0; i < this->m_workerNum; i++)
	{
		output_workerInfo << this->m_workerArray[i]->m_ID << "\t"
						  << this->m_workerArray[i]->m_Name << "\t"
						  << this->m_workerArray[i]->getDeptName() << "\t"
						  << this->m_workerArray[i]->getPosName() << endl;
	}

	output_workerInfo.close();
}




void workerManager::show_WorkerInfo()
{
	if (m_FileisEmpty){
		cout << "文件不存在或记录为空！" << endl;
	}
	else{
		for (int i = 0; i < this->m_workerNum; i++)
		{
			this->m_workerArray[i]->showInfo();
		}
	}
}



void workerManager::delete_WorkerInfo()
{
	if (m_FileisEmpty){
		cout << "文件不存在或记录为空！" << endl;
	}
	else{
		int input_ID;
		bool input_choice;
		bool input_choice_conf;
		bool FLAG = false;
		do
		{
			cout << "请输入员工编号: " << endl;
			cin >> input_ID;
			int index = isexist_ID(input_ID);
			if (index == -1)
			{
				cout << "删除失败，未找到该员工" << endl;
				cout << "请选择操作: 0-退出删除员工信息  1-重新输入员工编号" << endl;
				cin >> input_choice;
				FLAG = input_choice == true ? true : false;
			}
			else
			{
				cout << "该员工信息为: " << endl;
				this->m_workerArray[index]->showInfo();
				cout << "是否确定要删除该员工信息: " << endl;
				cout << "请选择操作: 0-No  1-Yes" << endl;
				cin >> input_choice_conf;
				if (input_choice_conf == false)
				{
					cout << "请选择操作: 0-退出删除员工信息  1-重新输入员工编号" << endl;
					cin >> input_choice;
					FLAG = input_choice == true ? true : false;
				}
				else if (input_choice_conf == true)
				{
					for (int i = index; i < this->m_workerNum -1; i++)
					{
						this->m_workerArray[i] = this->m_workerArray[i+1];
					}
					this->m_workerNum--;
					this->saveInfo();
					cout << "删除成功，员工记录已更改" << endl;
					FLAG = false;
				}
			}
		} while (FLAG == true);
	}
}



void workerManager::modify_WorkerInfo()
{
	if(m_FileisEmpty){
		cout << "文件不存在或记录为空！" << endl;
	}
	else{
		int input_ID;
		bool input_choice;
		bool input_choice_conf;
		bool FLAG = false;
		do
		{
			cout << "请输入员工的编号: " << endl;
			cin >> input_ID;
			int index = isexist_ID(input_ID);
			if (index == -1)
			{
				cout << "修改失败，未找到该员工" << endl;
				cout << "请选择操作: 0-退出修改员工信息  1-重新输入员工编号" << endl;
				cin >> input_choice;
				FLAG = input_choice == true ? true : false;
			}
			else
			{
				cout << "该员工信息为: " << endl;
				this->m_workerArray[index]->showInfo();
				cout << "是否确定要修改该员工信息: " << endl;
				cout << "请选择操作: 0-No  1-Yes" << endl;
				cin >> input_choice_conf;
				if (input_choice_conf == false)
				{
					cout << "请选择操作: 0-退出修改员工信息  1-重新输入员工编号" << endl;
					cin >> input_choice;
					FLAG = input_choice == true ? true : false;
				}
				else if (input_choice_conf == true)
				{
					int new_ID;
					string new_Name;
					int new_selectPosName;
					int new_selectDeptName;

					cout << "请输入新姓名: " << endl;
					cin >> new_Name;

					while (true)
					{
						cout << "请输入新编号: " << endl;
						cin >> new_ID;
						if (this->isexist_ID(new_ID) == -1 
						    || new_ID == this->m_workerArray[index]->m_ID){break;}
						cout << "该员工编号已存在，请重新输入" << endl;
					}
					
					cout << "请选择员工所属部门: " << endl;
					cout << "101-技术部\t"
						<< "102-销售部\t"
						<< "103-法务部\t"
						<< "104-财务部\t"
						<< "105-人力部" << endl;
					cin >> new_selectDeptName;

					cout << "请选择员工岗位: " << endl;
					cout << "1-总裁\t"
						<< "2-经理\t"
						<< "3-职员" << endl;
					cin >> new_selectPosName;

					Worker * temp_worker = NULL;
					switch (new_selectPosName)
					{
					case 1:
						temp_worker = new Boss(new_ID, new_Name, new_selectDeptName);
						break;
					case 2:
						temp_worker = new Manager(new_ID, new_Name, new_selectDeptName);
						break;
					case 3:
						temp_worker = new Employee(new_ID, new_Name, new_selectDeptName);
						break;
					default:
						break;
					}
					this->m_workerArray[index] = NULL;
					this->m_workerArray[index] = temp_worker;
					this->saveInfo();
					cout << "修改成功，员工记录已更改" << endl;
					FLAG = false;
				}
			}
		} while (FLAG == true);
	}
}



void workerManager::find_WorkerInfo()
{
	if (this->m_FileisEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int input_choice_find;
		bool FLAG_case;
		int input_choice;
		bool FLAG = false;
		cout << "请选择查找方式: 1-按编号  2-按姓名" << endl;
		cin >> input_choice_find;
		do{
			if (input_choice_find == 1)
			{
				int input_ID;
				int index;
				do{
					FLAG = false;
					FLAG_case = false;
					cout << "请输入查找的员工编号: " << endl;
					cin >> input_ID;
					index = this->isexist_ID(input_ID);
					if (index == -1)
					{
						cout << "查找失败，未找到该员工" << endl;
						cout << "请选择操作: 0-退出查找员工  1-重新输入编号  2-按照姓名查找" << endl;
						cin >> input_choice;
						FLAG_case = input_choice == 1 ? true : false;
						if (input_choice == 2)
						{
							FLAG = true;
							input_choice_find = 2;
						}
					}
					else
					{
						cout << "该员工信息为: " << endl;
						this->m_workerArray[index]->showInfo();
					}
				} while (FLAG_case == true);
			}
			else if (input_choice_find == 2)
			{
				string input_Name;
				int index[this->m_workerNum];
				do{
					cout << "请输入查找的员工姓名: " << endl;
					cin >> input_Name;
					bool isexist = false;
					FLAG = false;
					FLAG_case = false;
					int temp_Num = 0;
					for (int i = 0; i < this->m_workerNum; i++)
					{
						if (this->m_workerArray[i]->m_Name == input_Name)
						{
							index[temp_Num] = i;
							temp_Num++;
							isexist = true;
						}
					}
					if (isexist == false)
					{
						cout << "查找失败，未找到该员工" << endl;
						cout << "请选择操作: 0-退出查找员工  1-重新输入姓名  2-按照编号查找" << endl;
						cin >> input_choice;
						FLAG_case = input_choice == 1 ? true : false;
						if (input_choice == 2)
						{
							FLAG = true;
							input_choice_find = 1;
						}
					}
					else
					{
						cout << "共查询到" << temp_Num << "条信息: " << endl;
						for (int i = 0; i < temp_Num; i++)
						{
							this->m_workerArray[index[i]]->showInfo();
						}
					}
				} while (FLAG_case == true);
			}
			else
			{
				cout << "输入有误，请重新输入: " << endl;
				cin >> input_choice_find;
				FLAG = true;
			}
		} while (FLAG == true);
	}
	
}



void workerManager::sort_WorkerInfo()
{
	if (this->m_FileisEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int input_choice;
		cout << "请选择排序方式: 1-降序  2-升序" << endl;
		cin >> input_choice;
		for (int i = 0; i < this->m_workerNum; i++)
		{
			int MinMax = i;
			for (int j = i+1; j < this->m_workerNum; j++)
			{
				if (input_choice == 1)
				{
					if (this->m_workerArray[MinMax]->m_ID < this->m_workerArray[j]->m_ID)
					{
						MinMax = j;
					}
				}
				else				
				{
					if (this->m_workerArray[MinMax]->m_ID > this->m_workerArray[j]->m_ID)
					{
						MinMax = j;
					}
				}
				
			}	
			if (MinMax != i)
			{
				Worker * temp = this->m_workerArray[i];
				this->m_workerArray[i] = this->m_workerArray[MinMax];
				this->m_workerArray[MinMax] = temp;
			}
		}
		cout << "操作成功，排序后结果为: " << endl;
		this->show_WorkerInfo();
		this->saveInfo();
	}
}



void workerManager::clearInfo()
{
	cout << "是否确认清空: 1-Yes  0-No" << endl;

	bool input_choice;
	cin >> input_choice;

	if (input_choice == true)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream output_workerInfo(Filename, ios::trunc);
		output_workerInfo.close();

		if (this->m_workerArray != NULL)
		{
            for (int i = 0; i < this->m_workerNum; i++)
			{
				if (this->m_workerArray[i] != NULL)
				{
					delete this->m_workerArray[i];
					this->m_workerArray[i] = NULL;
				}
			}
			this->m_workerNum= 0;
			delete[] this->m_workerArray;
			this->m_workerArray = NULL;
			this->m_FileisEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
}





// -----------------------------------------------------------------------






int workerManager::getInfo_workerNum()
{
	ifstream input_workerInfo;
	input_workerInfo.open(Filename, ios::in);
	char buffer[1024];
	int num = 0;
	while ( input_workerInfo.getline(buffer, sizeof(buffer)) )
	{
		num++;
	}
	input_workerInfo.close();
	return num;
}


void workerManager::initial_workerArray()
{
	ifstream input_workerInfo;
	input_workerInfo.open(Filename, ios::in);
	int temp_ID;
	string temp_Name;
	string temp_DeptName;
	string temp_PosName;

	int index = 0;
	while (input_workerInfo >> temp_ID && input_workerInfo >> temp_Name && 
		   input_workerInfo >> temp_DeptName && input_workerInfo >> temp_PosName)
	{
		int temp_DeptID = DeptNametoID(temp_DeptName);
		Worker * temp_worker = NULL;
		if (temp_PosName == "职员")
		{
			temp_worker = new Employee(temp_ID, temp_Name, temp_DeptID);
		}
		else if (temp_PosName == "经理") 
		{
			temp_worker = new Manager(temp_ID, temp_Name, temp_DeptID);
		}
		else if (temp_PosName == "总裁") 
		{
			temp_worker = new Boss(temp_ID, temp_Name, temp_DeptID);
		}
		this->m_workerArray[index] = temp_worker;
		index++;
	}
}


int workerManager::DeptNametoID(string temp_DeptName)
{
	int temp_DeptID;
	if (temp_DeptName == "技术部") {temp_DeptID = 101;}
	else if (temp_DeptName == "销售部") {temp_DeptID = 102;}
	else if (temp_DeptName == "法务部") {temp_DeptID = 103;}
	else if (temp_DeptName == "财务部") {temp_DeptID = 104;}
	else if (temp_DeptName == "人力部") {temp_DeptID = 105;}
	return temp_DeptID;
}


int workerManager::isexist_ID(int input_ID)
{
	int index = -1;
	for (int i = 0; i < this->m_workerNum; i++)
	{
		if (this->m_workerArray[i]->m_ID == input_ID)
		{
			index = i;
			break;
		}
	}
	return index;
}