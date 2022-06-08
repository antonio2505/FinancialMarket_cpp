#include <iostream>
#include <vector>
#include <cmath>

class TimeSeries{
    
private:
    std::vector<double> m_value;

public:
    TimeSeries();
    ~TimeSeries();
    TimeSeries(const TimeSeries &v);
    TimeSeries &operator=(const TimeSeries &v);
    
    void addValue(double value);
    double stdDevv();
    double mean();
    size_t size();
    double elem(int i);

};

TimeSeries::TimeSeries(){
    
}

TimeSeries::~TimeSeries(){
    
}

TimeSeries::TimeSeries(const TimeSeries &v):m_value(v.m_value){
    
}

TimeSeries &TimeSeries::operator=(const TimeSeries &v){
    
    if(this!=&v){
        this->m_value=v.m_value;
    }
    return *this;
}

void TimeSeries::addValue(double value){
    
    m_value.push_back(value);
    
}

double TimeSeries::mean(){
    
    double sum=0;
    for(size_t i{0}; i<m_value.size(); ++i){
        sum+=m_value[i];
    }
    return sum/m_value.size();
}

double TimeSeries::stdDevv(){
    
    double m = mean();
    double sum = 0;
    for(size_t i{0}; i<m_value.size(); ++i){
        double val = m_value[i] - m;
        sum+=val*val;
    }
    return sqrt(sum/(m_value.size() - 1));
}

size_t TimeSeries::size(){
    
    return m_value.size();
}

double TimeSeries::elem(int i){
    
    return m_value[i];
    
}


class Correlation{
    
private:
    TimeSeries &m_tsA;
    TimeSeries &m_tsB;

public:
    Correlation(TimeSeries &a, TimeSeries &b);
    ~Correlation();
    Correlation(const Correlation &v);
    Correlation &operator=(const Correlation &v);
    
    double correlation();

};

Correlation::Correlation(TimeSeries &a, TimeSeries &b) 
 : m_tsA(a), m_tsB(b){
     
 }
 
 
Correlation::~Correlation(){
    
}

Correlation::Correlation(const Correlation &v)
 
 : m_tsA(v.m_tsA), m_tsB(v.m_tsB){
    
}

Correlation &Correlation::operator=(const Correlation &v){
    
    if(this!=&v){
        this->m_tsA = v.m_tsA;
        this->m_tsB = v.m_tsB;
    }
    return *this;
}

double Correlation::correlation(){
    
    double sum = 0;
    double meanA = m_tsA.mean();
    double meanB = m_tsB.mean();
    if(m_tsA.size()!=m_tsB.size()){
        std::cout<<"EURROR: Number of Observation is different"<<std::endl;
        return -1;
    }
    for(size_t i{0}; i<m_tsA.size(); ++i){
        
        auto val=(m_tsA.elem(i) - meanA)*(m_tsB.elem(i) - meanB);
        sum +=val;
    }
    double stDevA = m_tsA.stdDevv();
    double stDevB = m_tsB.stdDevv();
    sum/=(stDevA*stDevB);
    
    return sum / (m_tsA.size() - 1);
}


int main(){
    
    double price;
    
    TimeSeries tsa;
    TimeSeries tsb;
    
    for(;;){
        std::cout<<"Enter Price A: ";
        std::cin>>price;
        if(price == -1){
            break;
        }
        tsa.addValue(price);
        std::cout<<"Enter Price B: ";
        std::cin>>price;
        tsb.addValue(price);
    }
    
    Correlation corr(tsa, tsb);
    
    auto correlation = corr.correlation();
    
    std::cout<<std::endl;
     std::cout<<"=============================="<<std::endl;
    std::cout<<"Correalaion between A and B is: "<<correlation<<std::endl;
    return 0;
}