#include <iostream>
using namespace std;

//--------------------------------------------------------------------
//抽象CPU类
class CPU
{
public:
	virtual void calculate() = 0; 	//抽象的计算函数
};

//抽象显卡类
class VideoCard
{
public:
	virtual void display() = 0; 	//抽象的显示函数
};

//抽象内存条类
class Memory
{
public:
	virtual void storage() = 0; 	//抽象的存储函数
};


//--------------------------------------------------------------------


//电脑类
class Computer
{
public:
    Computer(CPU * cpu, VideoCard * videocard, Memory * memory)
    {
        m_cpu = cpu;
        m_videocard = videocard;
        m_memory = memory;
    }
    ~Computer()
	{
		//释放CPU零件
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//释放显卡零件
		if (m_videocard != NULL)
		{
			delete m_videocard;
			m_videocard = NULL;
		}
		//释放内存条零件
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory= NULL;
		}
    }



    void Work()
    {
        //让零件工作起来，调用接口
		m_cpu->calculate();
		m_videocard->display();
		m_memory->storage();
    }
private:
    CPU * m_cpu;
    VideoCard * m_videocard;
    Memory * m_memory;
};

//--------------------------------------------------------------------


// 具体厂商
//Intel厂商
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算了！" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示了！" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储了！" << endl;
	}
};

//Lenovo厂商
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算了！" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示了！" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储了！" << endl;
	}
};


//--------------------------------------------------------------------


// 组装不同的电脑
void test01()
{
    //第一台电脑零件
	CPU * intelCpu = new IntelCPU;
	VideoCard * intelCard = new IntelVideoCard;
	Memory * intelMem = new IntelMemory;
    //创建第一台电脑
    cout << "第一台电脑开始工作：" << endl;
    Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->Work();
    delete computer1;  // 会走Computer的析构函数，这里可以在析构中顺便把堆区中的零件数据释放
    // delete intelCpu;
    // delete intelCard;
    // delete intelMem;



    cout << "-----------------------" << endl;
	cout << "第二台电脑开始工作：" << endl;
	//第二台电脑组装
	Computer * computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->Work();
	delete computer2;



	cout << "-----------------------" << endl;
	cout << "第三台电脑开始工作：" << endl;
	//第三台电脑组装
	Computer * computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->Work();
	delete computer3;
}





int main()
{
    test01();
    return 0;
}
