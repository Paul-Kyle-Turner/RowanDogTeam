// run_script.cpp
//
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
using namespace std;
#include<conio.h>           // it may be necessary to change or remove this line if not using Windows

//#include "Blob.h"
#include "Feed.h"
#include <thread>
#include <future>
#include "json.hpp"
#include <fstream>


int main(void) {

	std::string name = "main";
	bool t = true;

	std::vector<Feed *> feed_list;
	std::vector<Lot *> lot_list;

	std::string stream0 = "rtsp://tech:tech@72.82.144.138:556/cam/realmonitor?channel=8&subtype=0"; //stream rtsp
	std::cout << "Please enter the number of RTSP feeds that you would like to open. Enter \"0\" for default";
	int rtsp_camera_feed_number;
	cin >> rtsp_camera_feed_number;
	if(rtsp_camera_feed_number == 0){
		feed_list.push_back(new Feed("rtsp://tech:tech@72.82.144.138:556/cam/realmonitor?channel=8&subtype=1", "Extra stream"));
		feed_list.push_back(new Feed("rtsp://admin:admin@192.168.1.137:554/cam/realmonitor?channel=1&subtype=0", "Parking Lot"));
	}
	else{
		for(int i = 0; i < rtsp_camera_feed_number; i++){
			cout << "Plaese enter the rtsp stream feed";
			std::string stream;
			cin >> stream
			cout << "Please enter the name of the stream";
			std::string name;
			cin >> name;
			feed_list.push_back(new Feed(stream, name));
		}
	}


	if(rtsp_camera_feed_number == 0){
		char chCheckForEscKey = 0;
		while (chCheckForEscKey != 27) {
			json j;
			for(int i = 0; i < feed_list.size(); i++){
				feed_list[i]->doStuff();
			}
			chCheckForEscKey = cv::waitKey(1);
			for(int i = 0; i < lot_list.size(); i++){
				j["lot_name"] = lot_list[i].getName();
				j["current_total"] = lot_list[i].getCurrent();
				j["max_cap"] = lot_list[i].getCurrent();
			}
			ofstream json_file;
			json_file.open("json.txt");
			json_file << j;
			json_file.close();
		}
	}


	if (chCheckForEscKey != 27) {               // if the user did not press esc (i.e. we reached the end of the video) @CW will go until user hits Q, removed if video ends, because rtsp feed should never end
		cv::waitKey(0);                         // hold the windows open to allow the "end of video" message to show
	}


	return 0;
}

