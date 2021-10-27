#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

const int WORK_MODE_VECTOR = 0;
const int WORK_MODE_MAP = 1;

struct FligtInfo {
	string departureDate;
	string departureTime;
	string destinationPoint;
	string arrivalTime;
	string flightNo;
};

class FlightSchedule
{
public:
	FlightSchedule();
	~FlightSchedule();
public:
	void setWorkMode(int mode); // 0 - режим работы с вектором или 1 - со словарем
	void readDataFromFile(string& iFileName); //exception
	void printInfoForDepDate(string& depDate, string& dstPoint);
private:
	int m_workMode = 0;

	vector<FligtInfo> m_vectFlights;

	multimap<string, FligtInfo> m_mapDatesFlights;
	multimap<string, FligtInfo> m_mapDestinatonsFlights;
};