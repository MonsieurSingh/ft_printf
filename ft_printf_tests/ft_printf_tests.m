//
//  ft_printf_tests.m
//  ft_printf_tests
//
//  Created by Devjyot Singh on 23/3/2024.
//

#import <XCTest/XCTest.h>
#include "../printf.h"
#include <stdio.h>

@interface ft_printf_tests : XCTestCase

@end

@implementation ft_printf_tests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void)test_with_percentage {
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("Hello, ft_printf%%");
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("Hello, ft_printf%%");
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

- (void)test_with_c {
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("Hello, ft_printf%c\n",'!');
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("Hello, ft_printf%c\n",'!');
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

- (void)test_with_c_comb {
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("Hello, ft_printf%-12c\n",'!');
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("Hello, ft_printf%-12c\n",'!');
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

- (void)test_with_s {
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("Hello, ft_printf%s","It's a string now");
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("Hello, ft_printf%s","It's a string now");
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

- (void)test_with_s_comb {
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("Hello, ft_printf[%-12.3s]","It's a string now");
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("Hello, ft_printf[%-12.3s]","It's a string now");
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
//	int	i = printf("Hello, ft_printf[%s]","It's a string now");
	XCTAssertEqual(30, ft_printf("Hello, ft_printf[%-12.3s]","It's a string now"));
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

- (void)test_with_d {
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("[%d]", -4123);
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("[%d]", -4123);
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

- (void)test_with_d_comb {
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("[%-12.3d]", 12132);
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("[%-12.3d]", 12132);
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

- (void)test_with_p {
	char *ptr = "ptr";
	FILE *temp_stdout = freopen("temp_output.txt", "w", stdout);
	ft_printf("[%p]", ptr);
	fclose(temp_stdout);
	FILE *temp_stdout2 = freopen("temp_output2.txt", "w", stdout);
	printf("[%p]", ptr);
	fclose(temp_stdout2);
	char printf_buffer[1024];
	char printf_buffer2[1024];
	FILE *temp_file = fopen("temp_output.txt", "r");
	FILE *temp_file2 = fopen("temp_output2.txt", "r");
	if (temp_file != NULL && temp_file2 != NULL) {
		fgets(printf_buffer, sizeof(printf_buffer), temp_file);
		fgets(printf_buffer2, sizeof(printf_buffer2), temp_file2);
		fclose(temp_file);
		fclose(temp_file2);
	}
	else
		XCTFail("Failed to open temporary file for reading.");
	remove("temp_output.txt");
	remove("temp_output2.txt");
	XCTAssert(strcmp(printf_buffer, printf_buffer2) == 0, @"Output from ft_printf and printf should match.");
}

//- (void)testPerformanceExample {
//	// This is an example of a performance test case.
//	[self measureBlock:^{
//		// Put the code you want to measure the time of here.
//		printf("Hello, printf!");  // Example of printf for performance comparison
//	}];
//}
//
@end
