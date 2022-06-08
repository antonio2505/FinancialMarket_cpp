#include <iostream>
#include <vector>
#include <cmath>

class CashFlowModel{
private:
    std::vector<double> m_cashPayment;//used to store stream of payment
    std::vector<int> m_timePeriod;// store the date when the payment occur
    double m_rate;
    double PresentValue(double futureValue, int timePeriod);//calculate the pv of each cashF

public:
    CashFlowModel(double r);//r: rate
    CashFlowModel(const CashFlowModel &r);//copy constrator
    CashFlowModel &operator =(const CashFlowModel &r);//copy assegnment
    ~CashFlowModel();
    
//    void setCashPayment(double c);
//    void setTimePeriod(int t);
//    void setRate(double r);
////    double getCashPayment();
////    double getTimePeriod();
//    double getRate();
    void addCashPayment(double value, int timePeriod);//used to store stream of payment
    double PresentValue();//calcule th PV of all cashF

};

CashFlowModel::CashFlowModel(double r) : m_rate(r){
    
}

CashFlowModel::~CashFlowModel(){
    
}

CashFlowModel::CashFlowModel(const CashFlowModel &r) : m_rate(r.m_rate){
    
}

CashFlowModel &CashFlowModel::operator =(const CashFlowModel &r){
    if(this!=&r){
        this->m_cashPayment=r.m_cashPayment;
        this->m_rate = r.m_rate;
        this->m_timePeriod=r.m_timePeriod;
    }
    return *this;
}


//void CashFlowModel::setCashPayment(std::vector<double> c){
//    
//    m_cashPayment=c;
//}
//
//void CashFlowModel::setTimePeriod(std::vector<int> t){
//    
//    m_timePeriod = t;
//}
//
//void CashFlowModel::setRate(double r){
//    
//    m_rate=r;
//}
//double getCashPayment(){
//    
//    return m_cashPayment;
//}
//double CashFlowModel::getTimePeriod(){
//    return m_timePeriod;
//}
//double CashFlowModel::getRate(){
//    return m_rate;
//}

void CashFlowModel::addCashPayment(double value, int timePeriod){
    
    m_cashPayment.push_back(value);
    m_timePeriod.push_back(timePeriod);
}

double CashFlowModel::PresentValue(double futureValue, int timePeriod){
    
    //pvalue for each cash payment
    double pValue = futureValue / pow(1+m_rate, timePeriod);
    std::cout<<std::endl;
    std::cout<<"Present Value for Year "<<timePeriod<<" : $"<<round(pValue)<<std::endl;
    return pValue;
}

double CashFlowModel::PresentValue(){
    //pvalue for all
    double total=0;
    for(unsigned i=0; i<m_cashPayment.size(); ++i){
        
        total += PresentValue(m_cashPayment[i], m_timePeriod[i]);
    }
    return round(total);
}





int main(){

    double rate{0};
    std::cout<<std::endl;
    std::cout<<"Enter Interest Rate in %: ";
    std::cin>>rate;
    std::cout<<std::endl;
    
    CashFlowModel cashF(rate/100);
    std::cout<<"tape 0 to finish entering"<<std::endl;
    std::cout<<std::endl;
    do{
        int timePeriod;
        std::cout<<std::endl;
        std::cout<<"Enter Period in Year     : ";
        std::cin>>timePeriod;
        if(timePeriod==0){
            break;
        }
        double value;
        std::cout<<"Enter Value for that year: ";
        std::cin>>value;
        cashF.addCashPayment(value,timePeriod);
        
    }while(1);
    std::cout<<std::endl;
    std::cout<<"=============================="<<std::endl;
    
    double result = cashF.PresentValue();
    
    std::cout<<std::endl;
    std::cout<<"The Present Value is: $"<<result<<" for all Period."<<std::endl;
    std::cout<<std::endl;
    
    
    return 0;
}