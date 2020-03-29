#include "ros/ros.h"
#include "exercise_2/exercise_2.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
#define N 200
unsigned long fibonacci[N];

bool service_callback(exercise_2::exercise_2::Request &req, exercise_2::exercise_2::Response &res){
	string out;
	
	for(int j=0; j<req.length; j++){
		out += to_string(fibonacci[req.index + j]);
		out += j==req.length-1? "\n" : ", ";
	}

	res.output = out;

	ROS_INFO("Ricevuti dati da client");

	return true;
}

int main(int argc, char **argv){
	fibonacci[0]=0;
	fibonacci[1]=1;
	for(int i=2; i<N; i++){
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	}
	ros::init(argc, argv, "service_server");
	ros::NodeHandle nh;
	ros::ServiceServer service=nh.advertiseService("exercise_2",service_callback);
	ROS_INFO("Pronto a ricevere.");
	ros::spin();
	return 0;
}
