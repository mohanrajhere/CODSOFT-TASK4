//TO DO LIST
#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;
struct Task{
    string description;
    bool completed;
};
vector<Task>taskList;
void addTask()
{
    Task newTask;
    cout<<"Enter task Description:";
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(cin,newTask.description);
    newTask.completed=false;
    taskList.push_back(newTask);
    cout<<"Task added successfully!"<<endl;
}
void viewTask(){
    cout<<"Task List:"<<endl;
    for(int i=0;i<taskList.size();i++){
        cout<<"["<<(taskList[i].completed?"X":"")<<"]"<<taskList[i].description<<endl;
    }
}
void markTaskAsCompleted(){
    int taskIndex;
    cout<<"Enter task number to mark as completed:";
    cin>>taskIndex;
    if(taskIndex>=1 && taskIndex<=taskList.size()){
        taskList[taskIndex-1].completed=true;
        cout<<"Task Marked as completed!"<<endl;
    }
    else
    cout<<"Invalid task number!"<<endl;
}
void removeTask(){
    int taskIndex;
    cout<<"Enter task number to remove:";
    cin>>taskIndex;
    if(taskIndex>=1&&taskIndex<=taskList.size()){
        taskList.erase(taskList.begin()+taskIndex-1);
        cout<<"Task Removed successfully!"<<endl;
    }
    else
    cout<<"Invalid task number!"<<endl;
}
int main()
{
    int choice;
    while (true){
        cout<<"To-Do list Manager"<<endl;
        cout<<"1.Add task"<<endl;
        cout<<"2.View Task"<<endl;
        cout<<"3.Mark Task as completed"<<endl;
        cout<<"4.To-Do list Manager"<<endl;
        cout<<"5.Exit"<<endl;
        cin>>choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        switch(choice){
            case 1:
            addTask();
            break;
            case 2:
            viewTask();
            break;
            case 3:
            markTaskAsCompleted();
            break;
            case 4:
            removeTask();
            break;
            case 5:
            return 0;
            default:
            cout<<"Invalid Choice!"<<endl;
        }
        cout<<endl;

    }
    return 0;
}
