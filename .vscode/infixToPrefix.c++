#include<iostream>
#include<stack>//مكتبة عشان استخدم الاستاك
#include<algorithm>//مكتبة عشان استخدم فانكشن isdigit 
using namespace std;
//* فانكشن بتوضلحى اولولية كل عملية حسابية 
int priority(char c){
    if(c=='-'||c=='+')
    {
        return 1;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else 
    return 0;   
}




//* ---------------------------------- *//

//* i want to convert infix to postfix 
//! (3+2) +7/2*((7+3)*2)
//* 32+72/73+2**+ "this is postfix "

//! algorthim to solve this problem 
//* اول خطوة هنعمل ستاك فاضى 
//* تانى خطوة لو لاقيت اى قوس مفتوح هعمل بوش فى الاستاك 
//* تالت خطوة لو لاقيت اى رقم هظهرة
//! رابع خطوة بالنسبة لى العمليات الحسابية 
//* هضيف العملية فى الاستاك 
//* ولكن فى حالة ان العملية اللى هتنضاف اكبر من او تساوى العملية اللى موجودة فى التوب 
//* هنفضل نعمل بوب للعملية لحد ما اقدر اضيفها 
//! فى حالة لاقيت قوس مقفول هعمل بوب لحد ما لاقى فاتحة القوس دة 

//*algorthim to solve this problem 

//* 1. Create a empty stack & empty string for output
//* 2. loop on the infix expression 
//* 3. on the the loop 
//! if its a digit then add it to the output 
//* يعنى فى حالة انه كان رقم ضيفة على ال اوت بوت 
//! else if ( the add it to the stack 
//* else if ) pop from stack to output until you reach (
//! if it s an operator the pop from stack until you can push it to the stack 


//* 4. if the stack is not empty then pop to the output the rest 
//* 5. print the output 

//* ---------------------------------- *//
string infixToPostfix(string exp)
{
stack<char> s; //كدة انا عملت ستاك فاضى 
string output ="";//عملت سترنج فاضى 

for(int i=0;i<exp.length();i++){
    if(exp[i] == ' ')
    continue;//* دة معناة فى حالة المستخدم دخل مسافة فاضية ف انا مش عاوز اضافها فعملت استمر 
    //* عشان يتجاهل الكود اللى بعد كدة ويروح يشوف جملة فور تانى 
    
    if(isdigit(exp[i])){
        output+=exp[i];
        //* الدالة دى وظيفتها فى حالة انه رقم ضيفة على الاوت بوت    
    }
    else if(exp[i]=='('){
        //*هنا فى حالة انى لاقيت قوس مفتوح هعملة بوش فى الاستاك 
        s.push('(');
    }
    else if(exp[i]==')'){
        while(s.top()!='('){
            //!هنا انا بعمل لوب طول ما التوب مش بيساوى فتحة القوس 
            //* يبقى حطلى التوب فى الاوت بوت 
            //* وبعد كدة شيلة بالبوب 
            output += s.top();
            s.pop();
        }
        s.pop();//مرة كمان عشان اشيل القوس دة  
        //* remove the '( '
        //*هنا فى حالة انى لاقيت قوس مقفول 
        //s.push('(');
    }
    //! فاضل جزء العمليات الحسابية 
    else{
        
        while(!s.empty() && priority(exp[i])<= priority(s.top()))
        {
            output+=s.top();
            s.pop();
        }
        s.push(exp[i]);//ضيف بقى العملية فى الاستاك
    }
}
    //*------------------------------*// 
    while(!s.empty())
    {
        output+=s.top();
        s.pop();
    }
return output;
}//end of for loop;



int main()
{
    string infix=("9-4*2");
cout<<"postfix Expression (First Output )"<<infixToPostfix(infix);




}
