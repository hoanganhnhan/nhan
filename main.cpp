#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;
class ThiSinh {
private:
	string hoten, namsinh;
	double toan, ly, hoa;
public:
	ThiSinh() {
	}
	ThiSinh(string hoten, string namsinh, double toan, double ly, double hoa) {
		this->hoten = hoten;
		this->namsinh = namsinh;
		this->toan = toan;
		this->ly = ly;
		this->hoa = hoa;
	}
	void setHoten(string hoten) {
		this->hoten = hoten;
	}
	string getHoten() {
		return hoten;
	}
	void setNamsinh(string namsinh) {
		this->namsinh = namsinh;
	}
	string getNamsinh() {
		return namsinh;
	}
	void setToan(double toan) {
		this->toan = toan;
	}
	double getToan() {
		return toan;
	}
	void setLy(double ly) {
		this->ly = ly;
	}
	double getLy() {
		return ly;
	}
	void setHoa(double hoa) {
		this->hoa = hoa;
	}
	double getHoa() {
		return hoa;
	}
	void nhapThiSinh() {
		cin.ignore();
		cout << "\nNhap ten: ";
		getline(cin, hoten);
		setHoten(hoten);
		cout << "Nhap nam sinh: ";
		getline(cin, namsinh);
		setNamsinh(namsinh);
		cout << "Nhap diem toan: ";
		cin >> toan;
		setToan(toan);
		cout << "Nhap diem ly: ";
		cin >> ly;
		setLy(ly);
		cout << "Nhap diem hoa: ";
		cin >> hoa;
		setHoa(hoa);
	}
	void xuanThiSinh() {
		cout << "\nHo ten: " << hoten;
		cout << "\nNam sinh: " << namsinh;
		cout << "\nDiem toan: " << toan;
		cout << "\nDiem ly: " << ly;
		cout << "\nDiem hoa: " << hoa;
	}
	double tongDiem() {
		double s;
		s = getToan() + getLy() + getHoa();
		if (s > 18)
			return 1;
		else
			return 0;
	}
};
void dsThiSinh(int& slThiSinh) {
	ofstream fileKQ, fileDS;
	fileKQ.open("ketqua.txt", ios::app);
	fileDS.open("dsThiSinh.txt", ios::app);
	ThiSinh dsthiSinh[100];
	for (int i = 0; i < slThiSinh; i++) {
		cout << "\nThi sinh " << i + 1 << ": ";
		fileDS << "\nThi sinh " << i + 1 << ": ";
		dsthiSinh[i].nhapThiSinh();
		fileDS << "\n\tHo ten:" << dsthiSinh[i].getHoten();
		fileDS << "\n\tNam sinh: " << dsthiSinh[i].getNamsinh();
		fileDS << "\n\tDiem toan: " << dsthiSinh[i].getToan();
		fileDS << "\n\tDiem ly: " << dsthiSinh[i].getLy();
		fileDS << "\n\tDiem hoa: " << dsthiSinh[i].getHoa();
		if (dsthiSinh[i].tongDiem() == 1) {
			fileKQ << dsthiSinh[i].getHoten() << " PASS" << endl;
		}
		else {
			fileKQ << dsthiSinh[i].getHoten() << " FAIL" << endl;
		}
	}
	fileDS.close();
	fileKQ.close();
}
void xuatKetQua() {
	ifstream fileKQ;
	fileKQ.open("ketqua.txt", ios::app);
	if (fileKQ.fail()) {
		cout << "\nFile khong mo duoc";
		return;
	}
	while (!fileKQ.eof()) {
		char line[255];
		fileKQ.getline(line, 255);
		cout << "\n" << line;
	}
	fileKQ.close();
}
void xuatlistThiSinh() {
	ifstream fileDS;
	fileDS.open("dsThiSinh.txt", ios::app);
	if (fileDS.fail()) {
		cout << "\nKhong mo duoc file";
		return;
	}
	while (!fileDS.eof()) {
		string s;
		getline(fileDS, s);
		cout << s << endl;
	}
	fileDS.close();
}
int main() {
	ThiSinh test;
	int key = 0;
	while (true) {
		system("cls");
		cout << "\n***************MENU****************";
		cout << "\n***1. Nhap ds thi sinh          ***";
		cout << "\n***2. Xuat ds thi sinh          ***";
		cout << "\n***3. Xuat ket qua trung tuyen  ***";
		cout << "\n***0. Thoat                     ***";
		cout << "\nNhap luc chon: ";
		cin >> key;
		switch (key) {
		case 1:
			cout << "\n1. Nhap danh sach thi sinh: ";
			int slThiSinh;
			cout << "\nNhap so luong thi sinh: ";
			cin >> slThiSinh;
			dsThiSinh(slThiSinh);
			cout << "\n<Nhan bat ky de tiep tuc>";
			system("pause");
			break;
		case 2:
			cout << "\n2. Xuat danh sach thi sinh: ";
			xuatlistThiSinh();
			cout << "\n<Nhan bat ky de tiep tuc>";
			system("pause");
			break;
		case 3:
			cout << "\n3. Xuat ket qua trung tuyen: ";
			xuatKetQua();
			cout << "\n<Nhan bat ky de tiep tuc>";
			system("pause");
			break;
		case 0:
			cout << "\nThoat\n";
			return 0;
		default:
			cout << "Khong co chuc nang nay";
			system("pause");
			break;
		}
	}
	
	return 0;
}