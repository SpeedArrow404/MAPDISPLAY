#include "headers.h"

int main(int argc, char** argv) {
	Controller FirstTry;
	FirstTry.GetParse();
	if(FirstTry.document == nullptr) cout<<"NULL"<<endl;
	FirstTry.FillDots();
	
	for(int i=0;i< FirstTry.gov.dots.size();i++){
		//cout << FirstTry.gov.dots[i]->id << endl;
	}
	
	

	vector<Dot*> path = FirstTry.GetWay(1, 8);

	for (int i = 0; i < path.size(); i++)
		cout << path[i]->id << endl;

	system("pause");
	return 0;
}
