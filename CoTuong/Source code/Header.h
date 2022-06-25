#pragma once
#include <iostream>
using namespace std;
// Class dẫn xuất của các quân cờ
class QuanCo
{
public:
	// Hàm thuần ảo để đa hình cách di chuyển của từng quân cờ
	virtual void DiChuyen() = 0;
	// Hàm thuần ảo để đa hình cách vẽ của từng quân cờ
	virtual void Ve() = 0;
protected:
	// Tọa độ x y của con cờ
	int x, y;
	// Xác định quân cờ thuộc phe nào
	bool z;
private:
	// Ba hàm sau chỉ dùng để hỗ trợ vẽ bàn cờ
	// Hàm để xem quân cờ có thể đi đến tọa độ đó không?
	friend bool IsOk(int, int, bool);
	// Hàm trả về xem ở tọa đọ đó có quân cờ cùng phe không ?
	friend bool IsCung(int, int, bool);
	// Hàm kiểm tra xem quan cờ ở tọa độ đó thuộc phe nào
	friend bool CheckQuanCo(int, int);
}; 
// Class con Mã được dẫn xuất từ class QuanCo
class Ma:public QuanCo
{
public:
	Ma();
	// Khởi tạo con Mã với tọa độ với phe biết trước
	Ma(int, int, bool);
	~Ma();
	void DiChuyen();
	void Ve();
private:
	
};
// Class con Pháo được dẫn xuất từ class QuanCo
class Phao:public QuanCo
{
public:
	Phao();
	// Khởi tạo con Pháo với tọa độ với phe biết trước
	Phao(int, int, bool);
	~Phao();
	void DiChuyen();
	void Ve();
private:
	
};
// Class con Sỹ được dẫn xuất từ class QuanCo
class Sy :public QuanCo
{
public:
	Sy();
	// Khởi tạo con Sỹ với tọa độ với phe biết trước
	Sy(int, int, bool);
	~Sy();
	void DiChuyen();
	void Ve();
private:
	
};
// Class con Tốt được dẫn xuất từ class QuanCo
class Tot :public QuanCo
{
public:
	Tot();
	// Khởi tạo con Tốt với tọa độ với phe biết trước
	Tot(int, int, bool);
	~Tot();
	void DiChuyen();
	void Ve();
private:
	bool QuaSong = 0;
	
};
// Class con Tượng được dẫn xuất từ class QuanCo
class Tuong :public QuanCo   // Class của con Tượng
{
public:
	Tuong();
	// Khởi tạo con Tượng với tọa độ với phe biết trước
	Tuong(int, int, bool);
	~Tuong();
	void DiChuyen();
	void Ve();
private:
	
};
// Class con Tướng được dẫn xuất từ class QuanCo
class TuongQuan : public QuanCo  // Class của con Tướng
{
public:
	TuongQuan();
	// Khởi tạo con Tướng với tọa độ với phe biết trước
	TuongQuan(int, int, bool);
	~TuongQuan();
	void DiChuyen();
	void Ve();
private:
	
};
// Class con Xe được dẫn xuất từ class QuanCo
class Xe : public QuanCo
{
public:
	Xe();
	// Khởi tạo con Xe với tọa độ với phe biết trước
	Xe(int, int, bool);
	~Xe();
	void DiChuyen();
	void Ve();
private:
	
}; 
// Hàm xử lý mạng chứa tọa của các quân cờ ban đầu
static void XuLiDuLieuDauVao(QuanCo***& ds)
{
	ds = new QuanCo * *[9];
	for (int index = 0; index < 9; ++index)
	{
		ds[index] = new QuanCo * [11];
		for (int j = 0; j < 11; ++j)
		{
			ds[index][j] = NULL;
		}
	}
}
// Hàm ghi chú thích các kí hiệu của các quân cờ
static void ChuThich()
{
	cout << "C: Tuong || S: Sy   || T: Tinh || M: Ma\n";
	cout << "X: Xe    || P: Phao || G: Tot\n";
	cout << "\n         Vi tri cac quan tren ban co\n";
	cout << "Tuong xanh (5, 10)           Tuong do (5, 10)\n";
	cout << "Si xanh (4, 1) va (1, 6)     Si do (4, 10) va (6, 10)\n";
	cout << "Tuong trang (3, 1) va (7, 1) Tuong do (3, 10) va (7, 10)\n";
	cout << "Ma xanh (1, 2) va (1, 8)     Ma do (2, 10) va (8, 10)\n";
	cout << "Xe xanh (1, 1) va (9, 1)     Xe do (1, 10) va (9, 10)\n";
	cout << "Phao xanh (2, 3) va (8, 3)   Phao do (2, 8) va (8, 8)\n";
	cout << "Tot xanh (1, 4), (4, 3),     Tot do (1, 7), (3, 7),\n";
	cout << "(4, 5), (4, 7) va (4, 9)     (7, 5), (7, 7) va (7, 9)\n";
	cout << "Press Enter to continue.";
	getchar();
}
bool IsOk(int, int, bool); // Hàm để xem quân cờ có thể đi đến tọa độ đó không?
bool IsChan(int, int); // Hàm cho biết chỗ đó có con cờ nào chưa?
bool IsCung(int, int, bool); // Hàm trả về xem ở tọa đọ đó có quân cờ cùng phe không?
// Hàm nhập tọa độ X Y 
static void NhapViTriDiChuyen(int& x, int& y)
{
	cin >> x;
	// Xác đinh là x == -1 để thoát
	if (x == -1)
	{
		x -= 1;
		return;
	}
	cin >> y;
	// Do mảng bắt đầu từ 0 còn tọa độ bàn cờ là 1 nên trừ đi 1 đơn vị
	x -= 1;
	y -= 1;
}
bool CheckChampion(int, int, bool); // Hàm kiểm tra ở vị trí đó có phải là con tướng không?