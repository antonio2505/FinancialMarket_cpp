/*
 * Calculate the compound interest accumulated by a given principal value after the
    passage of N time periods.
     * 
     * V = P(1+R)^N, where V: future value
     *                     P: present value
     *                     R: interest rate
     *                     N: number of period
     * 
     * 

 * Continous compounding :
 * 
 * V = P*e^(RN), the payment are made continuously over time.
 * */
 
 #include <iostream>
 #include <cmath> //to use pow and exp
 
 
class CompoundIntRate {
private:
    double m_rate; //R
    
public:
    CompoundIntRate(double rate);
    CompoundIntRate(const CompoundIntRate &v);
    CompoundIntRate &operator=(const CompoundIntRate &v);
    ~CompoundIntRate();
    
    double MultiplePeriod(double value, int numPeriod);//yearly
    
    double ContinuousCompounding(double value, int numPeriod);
    double ReturnOnInvestment(double value, double finalvalue); 
    
 };
 
CompoundIntRate::CompoundIntRate(double rate) : m_rate(rate){
    
}
CompoundIntRate::~CompoundIntRate(){
    
}
CompoundIntRate::CompoundIntRate(const CompoundIntRate &v) :m_rate(v.m_rate) {
    
}
CompoundIntRate &CompoundIntRate::operator =(const CompoundIntRate &v){
    if(this != &v){
        this->m_rate = v.m_rate;
    }
    return *this;
}

double CompoundIntRate::MultiplePeriod(double value, int numPeriod){
    
    double f = value*pow(1+m_rate, numPeriod);
    return f;
}

double CompoundIntRate::ContinuousCompounding(double value, int numPeriod){
    
    double f = value*exp(m_rate*numPeriod);
    return f;
}

double CompoundIntRate::ReturnOnInvestment(double value, double finalvalue){
    
    double returns = (finalvalue-value)/value;
    return returns*100;
}


///////////////////////////////////////////////////////////////////////////////

int main(){
    
    double rate{};
    double value{};
    int period{};
    
    
    std::cout<<"Enter your Rate in %: ";
    std::cin>>rate;
    std::cout<<"Enter your Investment Amount: ";
    std::cin>>value;
    std::cout<<"How many years you want to invest? : ";
    std::cin>>period;
    
    CompoundIntRate compIntrate{rate/100};
    double multiperiod = compIntrate.MultiplePeriod(value, period);
    double ROImultiperiod = compIntrate.ReturnOnInvestment(value, multiperiod);
    
    double continuousperiod=compIntrate.ContinuousCompounding(value, period);
    double ROIcontinuousperiod = compIntrate.ReturnOnInvestment(value, continuousperiod);
    
    std::cout<<std::endl;
    std::cout<<"================================="<<std::endl;

    std::cout<<"Rate             : "<<rate<<"%"<<std::endl;
    std::cout<<"Investment Amount: $"<<value<<std::endl;
    std::cout<<"Investment Period: "<<period<<" Years"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"MULTIPERIOD METHOD:"<<std::endl;
    std::cout<<"Your Future Value will be    : $"<<multiperiod<<" after "<<period<<" years"<<std::endl;
    std::cout<<"Your Returns On Investment is: "<<ROImultiperiod<<"% after "<<period<<" years"<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"================================="<<std::endl;

    std::cout<<"Rate             : "<<rate<<"%"<<std::endl;
    std::cout<<"Investment Amount: $"<<value<<std::endl;
    std::cout<<"Investment Period: "<<period<<" Years"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"CONTINUOUS METHOD:"<<std::endl;
    std::cout<<"Your Future Value will be    : $"<<continuousperiod<<" every "<<period<<" years"<<std::endl;
    std::cout<<"Your Returns On Investment is: "<<ROIcontinuousperiod<<"% after "<<period<<" years"<<std::endl;
    std::cout<<std::endl;
        
    return 0;
}