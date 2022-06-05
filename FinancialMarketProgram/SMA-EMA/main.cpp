#include <iostream>
#include <vector>


class MovingAverage {
    
private:
    int numPeriod;
    std::vector<double> m_prices;

public:
    MovingAverage(int period);
    MovingAverage(const MovingAverage &v);
    MovingAverage &operator=(const MovingAverage &v);
    ~MovingAverage();
    
    void addQuotedPrices(double close);
    std::vector<double> SMA();
    std::vector<double> EMA();

};

MovingAverage::MovingAverage(int period)
 : numPeriod(period){
     
 }
 
MovingAverage::MovingAverage(const MovingAverage &v) 
 : numPeriod(v.numPeriod){
     
 }
 
MovingAverage &MovingAverage::operator=(const MovingAverage &v){
    
    if(this!=&v){
        this->numPeriod = v.numPeriod;
    }
    return *this;
}

MovingAverage::~MovingAverage(){
    
}

void MovingAverage::addQuotedPrices(double close){
    
    m_prices.push_back(close);
    
}

std::vector<double> MovingAverage::SMA(){
    
    std::vector<double> ma;
    double sum=0;
    for(unsigned i{0}; i<m_prices.size(); ++i){
        sum+=m_prices[i];
        if(i>=numPeriod){
            ma.push_back(sum / numPeriod);
            sum-=m_prices[i-numPeriod];
        }
            
    }
    return ma;
}


std::vector<double> MovingAverage::EMA(){
    
    std::vector<double> ema;
    double sum = 0;
    double multiplier = 2.0 / (numPeriod+1);
    
    for(unsigned i{0}; i<m_prices.size(); ++i){
        sum+=m_prices[i];
        if(i==numPeriod){
            ema.push_back(sum / numPeriod);
            sum-=m_prices[i-numPeriod];
        }
        else if(i>numPeriod){
            double v=(1-multiplier)*ema.back()+multiplier*m_prices[i];
            ema.push_back(v);
        }
    }
    return ema;
}






int main(){
    
    int period{0};
    double prices{0};
    
    std::cout<<"Enter Period: ";
    std::cin>>period;
    std::cout<<std::endl;
    
    MovingAverage cal(period);
    for(;;){
        std::cout<<"Enter Price: ";
        std::cin>>prices;
        if(prices==0) break;
        cal.addQuotedPrices(prices);
    }
    
    std::vector<double> ma = cal.EMA();
    for(unsigned i{0}; i<ma.size(); ++i){
        std::cout<<"SMA value "<<i<<" = "<<ma[i]<<std::endl;
    }
    
    std::vector<double> ema = cal.SMA();
    for(unsigned i{0}; i<ema.size(); ++i){
        std::cout<<"MA value "<<i<<"  = "<<ema[i]<<std::endl;
    }
    
    return 0;
}