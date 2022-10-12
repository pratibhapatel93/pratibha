#include <iostream>

using namespace std;

class Employee
{
	public:
		Employee()
		{
			id = 100;
			hrs = 180;
			rate = 100;
		   	//cout <<"Employee Object Initialised" << endl;
		}
        Employee(int ii, int hh, float rr)
		{
			id = ii;
			hrs = hh;
			rate = rr;
			//cout <<"Employee Object Initialised via param ctor" << endl;

		}
	    int Get_Id()
		{
			return id;
		}
		//This pointer is a special pointer which holds address of an object 
		//on which member function was invoke
		// in main
		// Employee e
		// e.Set_Id(101) this pointer will hold address of e
		void Set_Id(int eid)  // Employee::Set_Id(Employee* this, eid)
		{
			id = eid;  // e->id = 101
		}

	    int Get_Hrs()
		{
			return hrs;
		}
		
		void Set_Hrs(int hh)
		{
			this->hrs = hh;

		}
		float Get_Rate()
		{
			return rate;
		}
		
		void Set_Rate(float rr)
		{
			rate = rr;

		}
        // member method whill a this pointer as first parameter
		// this->hrs they will access object data via this pointer
		// const means that the method will not change object data
		virtual double GetIncome() const // GetIncome(int hours, float rate)  <= wrong
		{
			double income = 0;
			income = hrs * rate;
			//hrs = 300; not allowed in const functions
			if ((hrs- 180) > 0)
				income = income + (hrs - 180) * 100;
		    return income; 

		}

		void PrintEmployee()
		{
			cout << "======== Printing Employee Data =========="<< endl;
			cout << "Employee ID : " << id << endl;
			cout << "Hours worked : " << hrs << endl;
			cout << "Rate per hour : " << rate << endl;
		}

	private:
		int id;
		int hrs;
		float rate;

};

class SalesPerson : public Employee
{
	public:
	    SalesPerson() : Employee()
		{
			sales = 0;
			//cout << "Salesperson Object initialised" << endl;
		}

		SalesPerson(int id, int hrs, float rate, double ss) : Employee(id, hrs, rate)
		{
			//cout << "Salesperson Object initialised via param ctor" << endl;
			sales = ss;
		}
		
		double Get_Sales()
		{
			return sales;
		}

		void Set_Sales(double ss)
		{
			sales = ss;
		}

		double GetIncome() const
		{
			double income = Employee:: GetIncome();
			income = income + 0.2 * sales;
			return income;

		}

		void PrintSalesPerson()
		{
			Employee::PrintEmployee();
			cout << "Sales is " << sales << endl;

		}
		~SalesPerson()
		{
			//cout << "SalesPerson Object Finalised" << endl;

		}
	private:
		double sales;
};

double GetTax(const Employee& e)  //e    sp
{
	double income = e.GetIncome(); // Employee::GetIncome(&e)
				  // e->vptr->GetIncome(e)
	double extra = income - 40000;
	if (extra > 0)
	       return extra * 0.1;
	else 
			return 0;
}

int main(void)
{
/*	cout << "Employee ID : " << e.Get_Id() << endl;
	cout << "Hours worked : " << e.Get_Hrs() << endl;
	cout << "Rate per hour : " << e.Get_Rate() << endl;
	e.Set_Id(101);
	e.Set_Hrs(200);
	e.Set_Rate(200);
	cout << "=============================" << endl;
	cout << "Employee ID : " << e.Get_Id() << endl;
	cout << "Hours worked : " << e.Get_Hrs() << endl;
	cout << "Rate per hour : " << e.Get_Rate() << endl;
	int id, hrs;
	float rate;
	cout << "Enter id / hrs / Rate" << endl;
	cin >> id >> hrs >> rate;
	Employee e1(id, hrs, rate); // parameterised ctor
	e1.PrintEmployee();
	cout << "Employees income is " << e.GetIncome() << endl; 
	cout << "Employees income is " << e1.GetIncome() << endl; 
	*/
	Employee e(101, 200, 200);
	e.PrintEmployee();
									//Employee::GetIncome()
	cout << "Employee income is " << e.GetIncome() << endl;
	cout << "Tax Applicable : " << GetTax(e) << endl;
    SalesPerson sp (104, 200, 200, 50000);
	sp.PrintSalesPerson();
	cout << "SP income is " << sp.GetIncome() << endl;
	                        //SalesPerson::GetIncome(&sp)
	cout << "Tax Applicable : " << GetTax(sp) << endl;
}





