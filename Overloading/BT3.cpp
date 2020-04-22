// g++ BT3.cpp -o main
// ./main
// g++ BT3.cpp
// ./a.out
#include <iostream>

using namespace std;

class CTimeSpan{
    private:
        int second;
    public:
        CTimeSpan(){}
        ~CTimeSpan(){}

        int GetSecond(){
            return second;
        }
        CTimeSpan(int _second){
            second = _second;
        }
        void Set(int hours, int minutes, int seconds){
            second = hours*60*60 + minutes*60 + seconds;
        }
        CTimeSpan(int hours, int minutes, int seconds){
            Set(hours, minutes, seconds);
        }
        friend const CTimeSpan operator +(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second+time2.second;
        }

        friend const CTimeSpan operator -(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second-time2.second;
        }

        void operator +=(CTimeSpan time){
            this->second += time.second;
        }
        
        CTimeSpan& operator++(){ //prefix
            ++this->second;
            return *this;
        }

        CTimeSpan operator++(int){ //postfix
            ++this->second;
            return *this;
        }
        // const CTimeSpan operator +(const CTimeSpan& time){
        //     return this->second+time.second;
        // }
        
        // const CTimeSpan operator -(const CTimeSpan& time){
        //     return this->second - time.second;
        // }
        
        friend bool operator ==(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second == time2.second;
        }
        
        friend bool operator >=(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second >= time2.second;
        }

        friend bool operator >(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second > time2.second;
        }
        friend bool operator <=(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second <= time2.second;
        }

        friend bool operator <(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second < time2.second;
        }

        friend bool operator !=(const CTimeSpan& time1, const CTimeSpan& time2){
            return time1.second != time2.second;
        }

        friend ostream& operator <<(ostream& os, CTimeSpan time){
            os << time.second;
	        return os;
        }
};

int& Get(int& x){
    int* p = &x;
    cout << p << endl;
    return *p;
}

int main(){
    // int x;
    // cin >> x;
    // cout << &x << endl;
    // cout << Get(x) << endl;
    CTimeSpan a, b, c;
    int hour, minute, second;
    cin >> hour >> minute >> second;
    a = CTimeSpan(hour,minute,second);
    cin >> hour >> minute >> second;
    b = CTimeSpan(hour,minute,second);
    c = a + b;
    a += b;
    //++a;
    a++;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "a>b: " << (a>b) << endl;
    cout << "a<b: " << (a<b) << endl;
    cout << "a=b: " << (a==b) << endl;
    cout << "a>=b: " << (a>=b) << endl;
    cout << "a<=b: " << (a<=b) << endl;
    cout << "a!=b: " << (a!=b) << endl; 
    return 0;
}