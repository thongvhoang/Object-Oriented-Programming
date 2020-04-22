#include <iostream>
using namespace std;

class Ctime{
    private:
        int hour, minute, second;
    public:
        Ctime(){
            this->hour = 0;
            this->minute = 0;
            this->second = 0;
        }
        ~Ctime(){}
        void Set(int hour, int minute, int second){
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }
        Ctime(int second){
            this-> hour = 0;
            this-> minute = 0;
            this-> second = second;
        }
        Ctime(int hour, int minute, int second): hour(hour), minute(minute), second(second){}

        void Transform(Ctime& time){
            if (time.second>=60*60) time.hour += time.second/3600, time.second %= 3600;
            if (time.second>=60) time.minute += time.second/60, time.second %= 60;
            if (time.minute>=60) time.hour += time.minute/60, time.minute %= 60;
        }
        friend const Ctime operator +(int x, const Ctime& time){
            Ctime temp = time;
            temp.second += x;
            temp.Transform(temp);            
            return temp;
        }
        
        friend const Ctime operator +(const Ctime& time1, const Ctime& time2){
            Ctime temp;
            temp.Set(time1.hour+time2.hour,time1.minute+time2.minute,time1.second+time2.second);
            temp.Transform(temp);            
            return temp;
        }

        friend const Ctime operator -(const Ctime& time1, const Ctime& time2){
            Ctime temp;
            temp.Set(0,0,time1.hour*60*60+time1.minute*60+time1.second-(time2.hour*60*60+time2.minute*60+time2.second));            
            temp.Transform(temp);            
            return temp;
        }
        
        friend const Ctime operator -(int x, const Ctime& time){
            Ctime temp = time;
            temp.second += temp.hour*60*60+temp.minute*60 - x;
            temp.Set(0,0,temp.second+temp.hour*3600+temp.minute*60 - x);
            temp.Transform(temp);
            return temp;
        }
        Ctime& operator++(){ //prefix
            ++this->second;
            this->Transform(*this);
            return *this;
        }

        Ctime operator++(int){ //postfix
            ++this->second;
            this->Transform(*this);
            return *this;
        }
        Ctime& operator--(){ //prefix
            this->Set(0,0,this->hour*60*60+this->minute*60-1+this->second);
            this->Transform(*this);
            return *this;
        }

        Ctime operator--(int){ //postfix
            this->Set(0,0,this->hour*60*60+this->minute*60-1+this->second);
            this->Transform(*this);
            return *this;
        }
        
        friend istream& operator >> (istream& in, Ctime& time){
            //cout << "Nhap gio, phut, giay: ";
            in >> time.hour >> time.minute >> time.second;
            return in;
        }

        friend ostream& operator << (ostream& out, Ctime& time){
            //cout << "Gio, phut, giay: ";
            out << time.hour << " " << time.minute << " " << time.second;
            return out;
        }
};

int main(){
    Ctime a(1,2,3), b(2,63,0);
    b = b-a;
    cout << b << endl;
    ++b;
    b++;
    ++b;
    b++;
    cout << b << endl;
    --b;
    b--;
    --b;
    cout << b << endl;
    return 0;
}