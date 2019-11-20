#include "ofMain.h"
#include "ofApp.h"
#include <curl/curl.h>
#include <iostream>


//========================================================================
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
    
    auto curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://web.housing.illinois.edu/MobileDining2/WebService/Search.aspx?t=json&k=7A828F94-620B-4EE3-A56F-328036CC3C04&id=4&from=2019-11-20&to=2019-11-20");
        
        std::string response_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl = NULL;
        
        std::cout << response_string << std::endl;
    }
}
