#include "sm2.h"
#include <iostream>

SM2::Grade user_answer()
{
    size_t answer;
    std::cout << "[0] again\n"
                 "[3] hard \n"
                 "[4] good \n"
                 "[5] easy \n";
                    
    std::cin >> answer;
    
    return static_cast<SM2::Grade>(answer);
}
int main()
{
	double easiness_factor = SM2::initial_easiness_factor;
	size_t repetition = 0;
	size_t interval   = 0;
	
	SM2::Grade grade = SM2::Grade::again;
	
	while(static_cast<size_t>(grade) < 3)
	{
		grade = user_answer();
		
		SM2::sm2(grade,easiness_factor,repetition,interval);
		
		std::cout << "\teasiness   : " << easiness_factor << '\n' << 
                     "\trepetition : " << repetition      << '\n' << 
                     "\tinterval   : " << interval        << '\n' ;
	}	
}
