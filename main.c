//
//  main.c
//  ft_printf
//
//  Created by Devjyot Singh on 23/3/2024.
//

#include "printf.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	char	*str;
	
	str = ft_itoa(100);
	printf("%p\n", str);
	ft_printf("%p\n", str);
	return (OK);
}
