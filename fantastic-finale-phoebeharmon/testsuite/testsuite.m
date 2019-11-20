//
//  testsuite.m
//  testsuite
//
//  Created by Phoebe Harmon on 11/20/19.
//

#import <XCTest/XCTest.h>
#include "dataprocessor.hpp"
#include "item.hpp"
#include <json.hpp>
#include <string>
#include <vector>

@interface testsuite : XCTestCase

@end

@implementation testsuite

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testDataProcessor {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    std::string url_string = "https://web.housing.illinois.edu/MobileDining2/WebService/Search.aspx?t=json&k=7A828F94-620B-4EE3-A56F-328036CC3C04&id=4&from=2019-11-20&to=2019-11-20";
    
    DataProcessor processor;
    nlohmann::json json_object = processor.ConvertStringToJson(processor.ReadUrl(url_string));
    
    std::vector<Item> items = processor.ConvertJsonToItems(json_object);

    XCTAssert(items[0].item_id == 222);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
