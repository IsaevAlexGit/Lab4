#include "FlightSchedule.h"
#include <iostream>
#include <fstream>
#include <algorithm>

FlightSchedule::FlightSchedule() {
}


FlightSchedule::~FlightSchedule() {
}

void FlightSchedule::setWorkMode(int mode) {
	m_workMode = mode;
}

void FlightSchedule::readDataFromFile(string& iFileName) {
	ifstream iDataFile(iFileName);
	if (!iDataFile.is_open()) throw new exception("Ошибка открытия файла"); //exception

	string depDate, depTime, dstPoint, arrTime, flightNo;

	while (!iDataFile.eof()) {
		iDataFile >> depDate >> depTime >> dstPoint >> arrTime >> flightNo;
		if (m_workMode == WORK_MODE_VECTOR)
			m_vectFlights.push_back({ depDate, depTime, dstPoint, arrTime, flightNo });

		else if (m_workMode == WORK_MODE_MAP) {
			m_mapDatesFlights.insert(pair<string, FligtInfo>(depDate, { depDate, depTime, dstPoint, arrTime, flightNo }));
			//m_mapDestinatonsFlights.insert(pair<string, FligtInfo>(dstPoint, { depDate, depTime, dstPoint, arrTime, flightNo }));
		}
	}

	iDataFile.close();
}

struct foSearchDepDateStr {
	string srchDate;
	string srchDst;
	foSearchDepDateStr(string srchDate, string srchDst) : srchDate(srchDate), srchDst(srchDst) {}

	bool operator()(FligtInfo fi) {
		return fi.departureDate == srchDate && fi.destinationPoint == srchDst;
	}
};

void FlightSchedule::printInfoForDepDate(string& depDate, string& dstPoint) {
	if (m_workMode == WORK_MODE_VECTOR) {
		auto it = m_vectFlights.begin();

		while (it != m_vectFlights.end()) {
			it = find_if(it, m_vectFlights.end(), foSearchDepDateStr(depDate, dstPoint));
			if (it != m_vectFlights.end()) {
				cout << it->flightNo << " " << it->departureTime << " " << it->arrivalTime << endl;
				it++;
			}
		}
	}
	///////
	else if (m_workMode == WORK_MODE_MAP) {
		auto itm = m_mapDatesFlights.begin();
		int cntr = m_mapDatesFlights.count(depDate);
		itm = m_mapDatesFlights.find(depDate);

		for (int i = 0; i < cntr; ++i, ++itm) {
			if(itm->second.destinationPoint == dstPoint)
				cout << itm->second.flightNo << " " << itm->second.departureTime << " " << itm->second.arrivalTime << endl;
		}
	}
}
/*
1
20.11.2017 SMW

*/