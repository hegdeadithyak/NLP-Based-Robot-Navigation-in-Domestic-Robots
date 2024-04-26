#include <ros/ros.h>
#include <fstream>
#include <vector>
#include <utility>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/String.h>
#include <map>

std::string filePath = "/home/vikas/my_ws/src/rst_pkg/My_locations/stored_locations.txt";
std::fstream file(filePath,std::ios::in);
std::vector<std::pair<double,double>> location;
int i ,j = 0;
std::string words; 
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MovebaseClient ; 

void Assign_locations()
{
   double value ; 
   if(file.is_open())
   {
        while(1)
        {
            file>>value;
            if(i%2 == 0)
            {
              location.push_back(std::make_pair(value,0.0));
            }
            else
            {
              location[j].second = value;
              j++;
            }
            i++;
            if(file.eof())
            {
                break;
            }
        }
   file.close();
   }
   else
   {
     ROS_ERROR_ONCE("Can't open file !! \n");
   }
}

void check_locations()
{
  std::cout<<"Your locations are : "<<std::endl;
    for(int ii = 0 ; ii<= j-1; ii++)
    {
        std::cout<<location[ii].first<<" "<<location[ii].second<<std::endl;
    }

}

void move_to_location(std::map<std::string,std::pair<double,double>> coordinates , std::string words)
{
   std::cout<<"Your x location is : "<<coordinates[words].first<<std::endl;
   std::cout<<"Your y location is : "<<coordinates[words].second<<std::endl;
  MovebaseClient ac("move_base",true);
  
  while(!ac.waitForServer(ros::Duration(5.0)))
  {
    ROS_INFO("Waiting for the move_base action server to connect !! \n");
  }

  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x =  coordinates[words].first; 
  goal.target_pose.pose.position.y =  coordinates[words].second;
  goal.target_pose.pose.orientation.w = 1;

  ac.sendGoal(goal);
  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Congrats you moved to your desired coordinates \n");
  }
  else
  {
    ROS_ERROR_ONCE("There must be some problem in executing your commands , Couldn't go to the desired location \n");
  }

}

void map_coordinates_and_words(std::string words)
{
  std::map<std::string,std::pair<double,double>> coordinates;
  coordinates.insert(std::make_pair("one",std::make_pair(location[0].first,location[0].second)));
  coordinates.insert(std::make_pair("two",std::make_pair(location[1].first,location[1].second)));
  coordinates.insert(std::make_pair("three",std::make_pair(location[2].first,location[2].second)));
  coordinates.insert(std::make_pair("for",std::make_pair(location[3].first,location[3].second)));

  std::cout<<coordinates[words].first<<" "<<coordinates[words].second<<std::endl;
  move_to_location(coordinates, words);
}

void filterout_words(std::string &words)
{
  std::string a[] = {"one","two","three","for"};
  for(int i = 0 ; i<= a->length() ; i++)
  {
    if(words == a[i])
    {
      map_coordinates_and_words(words);
    }
  }
}

void callback(const std_msgs::String::ConstPtr &msg)
{
  words = msg->data;
  std::cout<<"You said : "<<words<<std::endl;
  filterout_words(words);
}

int main(int argc , char** argv)
{
  ros::init(argc , argv , "sendlocationstomovebase");
  Assign_locations(); 
  check_locations();
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<std_msgs::String>("/speech_recognition/final_result",1000,callback);
  ros::spin();
  return 0;
}     