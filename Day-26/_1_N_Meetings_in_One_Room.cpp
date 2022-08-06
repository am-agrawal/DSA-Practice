#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nMeetings(vector<int>& start, vector<int>& end) {
  // Meetings => (endTime, startTime, noOfMeeting)
  vector<vector<int>> meetings;
  vector<int> possibleMeetings;
  int endTime;

  for(int i = 0; i < start.size(); i++) {
    meetings.push_back({end[i], start[i], i+1});
  }

  sort(meetings.begin(),meetings.end());

  endTime = meetings[0][0];
  possibleMeetings.push_back(meetings[0][2]);

  for(auto meeting : meetings) {
    if(meeting[1] > endTime) {
      endTime = meeting[1];
      possibleMeetings.push_back(meeting[2]);
    }
  }

  return possibleMeetings;
}

int main() {
  // Meeting no.       1  2  3  4  5  6
  vector<int> start = {1, 0, 3, 8, 5, 8};
  vector<int> end =   {2, 6, 4, 9, 7, 9};

  vector<int> possibleMeetings = nMeetings(start, end);

  for(auto it : possibleMeetings) {
    cout << it << endl;
  }

  return 0;
}