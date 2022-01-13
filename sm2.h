#pragma once
#include <cmath>

namespace SM2{
    enum class Grade
    {    
        again = 0, // failure to recall
        hard  = 3, // effort to recall
        good  = 4, // some hesitation
        easy  = 5  // perfect recall
    };

    static const double initial_easiness_factor = 2.5;
    static const double minimum_easiness_factor = 1.3;

    /*
        grade           : indicate how easy or difficuty was recall
        
        easiness factor : indicate how quickly interval grows
        
        repetition      : it is the number of times
                          it has been successfully recalled
                          
        interval        : it is the length of time (in days)
    */
    static void sm2(Grade grade,
                    double & easiness_factor,
                    size_t & repetition,
                    size_t & interval)
    {
        const size_t quality = static_cast<size_t>(grade);
        
        if(quality >= 3)
        {
            if(repetition == 0)        
                interval = 1;
            else if(repetition == 1)        
                interval = 6;
            else        
                interval  = std::round(interval * easiness_factor);
            
            repetition += 1;
        }else
        {
            repetition = 0;
            interval   = 1;
        }
        
        easiness_factor += (0.1 -  (5 - quality) * 
                           (0.08 + (5 - quality) * 0.02));
        
        if(easiness_factor < minimum_easiness_factor)    
            easiness_factor = minimum_easiness_factor;    
    }
}
