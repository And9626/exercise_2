#include "ros/ros.h"
#include "exercise_2/exercise_2.h"
#include <iostream>
#include <sstream>

using namespace std;
#define N 200

int main(int argc, char **argv){
	
	ros::init(argc, argv, "service_client");
	ros::NodeHandle nh;
	ros::ServiceClient client=nh.serviceClient<exercise_2::exercise_2>("exercise_2");
	
	while(ros::ok()){
		exercise_2:: exercise_2 srv;
		int in1, in2;
		cout<<"Inserire l'indice (numero compreso tra 0 e "<<N-1<<"): ";
		cin>>in1;
		cout<<"Inserire lunghezza: (numero compreso tra 0 e "<<N-in1<<"): ";
		cin>>in2;		
		srv.request.index = in1;
		srv.request.length = in2;
		if(client.call(srv)){
			cout<<"Output: "<<srv.response.output<<endl;
		}

		else {
			ROS_ERROR("NO service");
		}
	ros::spinOnce();
	
	}
	return 1;
}	

