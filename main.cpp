#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>           // it may be necessary to change or remove this line if not using Windows

//#include "Blob.h"
#include "Feed.h"
#include <thread>
#include <future>



int main(void) {
	
	std::string stream = "rtsp://tech:tech@72.82.144.138:556/cam/realmonitor?channel=8&subtype=0"; //stream rtsp
	std::string name = "main";
	bool t = true;
	
	std::vector<Feed *> feed_list;
	
	//while (t)
	//{
		

		//std::cout << "Opening feed: Press 1 for live, 2 for extra\n";
		int value = 0;
		//std::cin >> value;
	
	
		
		//Feed *feed2 = new Feed("rtsp://tech:tech@72.82.144.138:556/cam/realmonitor?channel=8&subtype=1", "extra stream");
		//Feed *feed1 = new Feed(stream, name);
		feed_list.push_back(new Feed("rtsp://tech:tech@72.82.144.138:556/cam/realmonitor?channel=8&subtype=1", "Extra stream"));
		feed_list.push_back(new Feed("rtsp://admin:admin@192.168.1.137:554/cam/realmonitor?channel=1&subtype=0", "Parking Lot"));
		feed_list.push_back(new Feed(stream, name));
		char chCheckForEscKey = 0;
		while (chCheckForEscKey != 27) {
			feed_list[0]->doStuff();
			feed_list[1]->doStuff();
			feed_list[2]->doStuff();
			chCheckForEscKey = cv::waitKey(1);

		}

		if (chCheckForEscKey != 27) {               // if the user did not press esc (i.e. we reached the end of the video) @CW will go until user hits Q, removed if video ends, because rtsp feed should never end
			cv::waitKey(0);                         // hold the windows open to allow the "end of video" message to show
		}
	

	
	
	
		return 0;
}

