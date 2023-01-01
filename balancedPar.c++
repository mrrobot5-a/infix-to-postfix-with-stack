#include<iostream>
#include<stack> //*الخاصة بالاستاك
using namespace std;
bool isPair(char open , char close)
{            if((open=='{' &&  close == '}')) return true;
                else if(open=='[' &&  close == ']')return true;
                else if(open=='(' &&  close == ')')return true;
                else return false;

}
//! نعرف الاول هدفنا ايه 
//* هدفنا اننا نعمل فانكشن تشوف لو مستخدم دخل نص فيه اقواس هل كل الاقواس اتفتحت واتقفلت ولا لا لاء
bool balancedPair(string exp){
//*فانكشن من نوع بول عشان ترجع صح او غلط وبتستقبل نص
stack <char> s; //دة زى اوبجت يعنى اقدر استدعى الفانكشن الخاصة بالاستاك 3
    for(int i =0;i<exp.length();i++){
        //!
        //* الفانشكن اللى اسمها length
        //! بتجبلى طول النص 
        if(exp[i]=='(' ||exp[i]=='{' ||exp[i]=='[')//open case 
        {
            s.push(exp[i]);//دة معناة انى هاخد اللى اتكتب دة واحطة فى البوش
        }
        else if(exp[i]==')' ||exp[i]=='}' ||exp[i]==']')//close case 
        {
            
            if(s.empty()) return false;
                else if(isPair(s.top(),exp[i])==false) return false;
            else
                s.pop();
        }
    }
    return s.empty()?true:false;
}

int main()
{
string s;
cout<<"enter an expression :";
cin>>s;
if(balancedPair(s))
{
    cout<<"is balanced "<<endl;
}
else cout<<"expression is not balanced"<<endl;
}