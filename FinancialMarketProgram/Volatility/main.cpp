#include <iostream>
#include <vector>
#include <cmath>


class Volatility {
    
private:
    std::vector<double> m_price;

public:
    Volatility();
    ~Volatility();
    Volatility(const Volatility &v);
    Volatility &operator=(const Volatility &v);
    
    void addPrice(double price);
    double rangeVolatility();
    double stdDev();
    double mean();
    double avgDailyRange();
    
};

Volatility::Volatility(){
    
}

Volatility::~Volatility(){
    
}

Volatility::Volatility(const Volatility &v) : m_price(v.m_price){
    
}

Volatility &Volatility::operator=(const Volatility &v){
    if(this != &v){
        this->m_price = v.m_price;
    }
    return *this;
}

void Volatility::addPrice(double price){
    m_price.push_back(price);
}

double Volatility::rangeVolatility(){
    
    if(m_price.size() <1){
        return 0;
    }
    
    double min = m_price[0];
    double max = min;
    for(unsigned i{0}; i<m_price.size(); ++i){
        
        if(m_price[i] < min){
            min = m_price[i];
        }
        if(m_price[i]>max){
            max = m_price[i];
        }
    }
    return max-min;
}

double Volatility::mean(){
    
    double sum=0;
    for(unsigned i{0}; i<m_price.size(); ++i){
        sum+=m_price[i];
    }
    return sum / m_price.size();
}

double Volatility::stdDev(){
    
    double m = mean();
    double sum = 0;
    for(unsigned i{0}; i<m_price.size(); ++i){
        double val = m_price[i] - m;
        sum+=val*val;
    }
    return sqrt(sum / (m_price.size() - 1));
}


double Volatility::avgDailyRange(){
    
    unsigned long n = m_price.size();
    
    if(n < 2){
        return 0;
    }
    double previous = m_price[0];
    double sum = 0;
    for(unsigned i{0}; i<m_price.size(); ++i){
        double range = abs(m_price[i] - previous);
        sum+=range;
    }
    return sum / n -1;
}






int main(){
    
    double price{0};
    
    Volatility vol;
    
    
    std::cout<<"tape -1 to finish entering,"<<std::endl;
    std::cout<<std::endl;
    
    for(;;){
        
        std::cout<<"Enter Price: ";
        std::cin>>price;
        if(price==-1){
            break;
        }
        vol.addPrice(price);
    }
    std::cout<<std::endl;
    std::cout<<"============================================"<<std::endl;
    std::cout<<"range volaility is    : "<<vol.rangeVolatility()<<std::endl;
    std::cout<<"average daily range is: "<<vol.avgDailyRange()<<std::endl;
    std::cout<<"standard deviation is : "<<vol.stdDev()<<std::endl;
    
    
    return 0;
}