#include <iostream>
using namespace std;

class Cdate{
    private:
        int day, month, year;
    public:
        Cdate(){
            this->day = 0;
            this->month = 0;
            this->year = 0;
        }
        ~Cdate(){}
        Cdate(int day){
            Set(0,0,day);
        }
        Cdate(int year, int month, int day): day(day), month(month), year(year){}
        void Set(int year, int month, int day){
            this->year = year;
            this->month = month;
            this->day = day;
        }
        void Transform(Cdate& cdate){
            if (cdate.day>=365) cdate.year += cdate.day/365, cdate.day %= 365;
            if (cdate.day>=30) cdate.month += cdate.day/30, cdate.day %= 30;
        }
        /*
        friend const Cdate operator +(int x, const Cdate& date){
            Cdate temp = date;
            temp.day += x;
            temp.Transform(temp);
            return temp;
        }
        */
        /*
        friend const Cdate operator -(int x, const Cdate& date){
            Cdate temp = date;
            temp.Set(0,0,temp.year*365+temp.month*30+temp.day-x);
            temp.Transform(temp);
            return temp;
        }
        */
        
        friend const Cdate operator +(const Cdate& date1, const Cdate& date2){
            Cdate temp = date1;
            temp.Set(0,0,temp.year*365+temp.month*30+temp.day+(date2.year*365+date2.month*30+date2.day));
            temp.Transform(temp);
            return temp;
        }
        
        friend const Cdate operator -(const Cdate& date1, const Cdate& date2){
            Cdate temp = date1;
            temp.Set(0,0,temp.year*365+temp.month*30+temp.day-(date2.year*365+date2.month*30+date2.day));
            temp.Transform(temp);
            return temp;
        }

        Cdate& operator++(){ //prefix
            ++this->day;
            this->Transform(*this);
            return *this;  
        }
        Cdate operator++(int){ //postfix
            ++this->day;
            this->Transform(*this);
            return *this;
        }
        Cdate& operator--(){ //prefix
            this->Set(0,0, this->year*365+this->month*30+this->day-1);
            this->Transform(*this);
            return *this;
        }
        Cdate operator--(int){ //postfix
            this->Set(0,0, this->year*365+this->month*30+this->day-1);
            this->Transform(*this);
            return *this;
        }
        friend istream& operator >> (istream& in, Cdate& date){
            in >> date.year >> date.month >> date.day;
            return in;
        }
        friend ostream& operator << (ostream& out, Cdate& date){
            out << date.year << " " << date.month << " " << date.day;
            return out;
        }
};

int main(){
    Cdate a, b;   
    cout << "Nhap ngay thang nam: "; cin >> a;
    cout << "Nhap ngay thang nam: "; cin >> b;
    //a = a-b;
    --a;
    a--;
    --a;
    --a;
    cout << a << endl;
    
    return 0;
}