#include <iostream>
#include "Draw.h"
#include "Header.h"
using namespace std;
QuanCo*** ds;
int X1 = 4, Y1 = 0;// Tọa độ của con Tướng xanh và gán vị trí lúc đầu
int X2 = 4, Y2 = 9;// Tọa độ của con Tướng đỏ và gán vị trí lúc đầu
bool Xanh = 1; // Biến xác định con Tướng xanh còn ở trên bàn cờ không
bool Do = 1; // Biến xác định con Tướng đỏ còn ở trên bàn cờ không
// Hàm kiểm tra ở vị trí đó có phải là con tướng không?
bool CheckChampion(int x, int y, bool zz)
{
	if (zz && x == X1 && y == Y1)
	{
		return 1;
	}
	if (!zz && x == X2 && y == Y2)
	{
		return 1;
	}
	return 0;
}
// Hàm để xem quân cờ có thể đi đến tọa độ đó không?
bool IsOk(int x, int y, bool zz)
{
	if (x < 0 || y < 0 || x > 8 || y > 9) return 0;
	if (!ds[x][y]) return 1;
	if (ds[x][y]->z == zz) return 0;
	return 1;
}
// Hàm trả về xem ở tọa đọ đó có quân cờ cùng phe không?
bool IsCung(int x, int y, bool zz)
{
	return (ds[x][y]->z == zz);
}
// Hàm cho biết chỗ đó có con cờ nào chưa?
bool IsChan(int x, int y)
{
	if (x < 0 || y < 0 || x > 8 || y > 9) return 1;
	return (ds[x][y]);
}
// Hàm kiểm tra giá trị nhập vào đã đúng cú pháp chưa
bool Check(int x, int y)
{
	if (x < 0 || y < 0 || x > 8 || y > 9) return 0;
	return 1;
}
// Hàm cập nhật vị trí mới cho quân cờ 
void Update(int x1, int y1, int x2, int y2)
{
	// Nếu vị trí đó có quân cờ thì xóa quân cờ đó
	if (IsChan(x2, y2)) delete ds[x2][y2];
	// Đặt vị trí mới cho quân cờ
	ds[x2][y2] = ds[x1][y1];
	// Đặt vị trí cũ không có quân cờ
	ds[x1][y1] = NULL;
	// Nếu ăn vào Tướng xanh thì thay đổi biến để biết bên Đỏ thắng
	if (x2 == X1 && y2 == Y1)
	{
		Xanh = 0;
	}
	// Nếu ăn vào Tướng đỏ thì thay đổi biến để biết bên Xanh thắng
	else if (x2 == X2 && y2 == Y2)
	{
		Do = 0;
	}
	// Nếu di chuyển Tướng xanh
	if (x1 == X1 && y1 == Y1)
	{
		X1 = x2;
		Y1 = y2;
	}
	// Nếu di chuyển Tướng đỏ
	else if (x1 == X2 && y1 == Y2)
	{
		X2 = x2;
		Y2 = y2;
	}
}
// Hàm kiểm tra xem quan cờ ở tọa độ đó thuộc phe nào
bool CheckQuanCo(int x, int y)
{
	return (ds[x][y]->z);
}
// Hàm chơi 
void Play()
{
	int x, y;
	while (Xanh && Do)
	{
		while (1)
		{
			cout << "Den luot Xanh di:\n";
			cout << "Nhap toa do con co (x,y)(-1 de thoat): ";
			NhapViTriDiChuyen(x, y);
			if (x == -2) return;
			if (Check(x, y) && IsChan(x,y) && CheckQuanCo(x, y) && ds[x][y])
			{
				cout << endl;
				ds[x][y]->DiChuyen();
				// Nếu đã đi thì chuyển bên
				if (!IsChan(x, y))
				{
					clrscr();
					break;
				}
			}
		}
		while (1)
		{
			cout << "Den luot Do di:\n";
			cout << "Nhap toa do con co (x,y)(-1 de thoat): ";
			NhapViTriDiChuyen(x, y);
			if (x == -2) return;
			if (Check(x, y) && IsChan(x, y) && !CheckQuanCo(x, y) && ds[x][y])
			{
				cout << endl;
				ds[x][y]->DiChuyen();
				// Nếu đã đi thì chuyển bên
				if (!IsChan(x, y))
				{
					clrscr();
					break;
				}
				
			}
		}
	}
}
int main()
{
	cout << " Phong to ma man hinh va an mot phim Enter de tiep tuc";
	getchar();
	system("cls");
	gotoxy(0, 0);
	VeBanCo(ds);
	gotoxy(0, 0);
	// Xuất ra chú thích để người dùng hiểu
	ChuThich();
	// Hàm chơi
	Play();
	system("cls");
	system("pause");
	return 0;
}