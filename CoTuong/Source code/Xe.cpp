#include "Header.h"
#include "GraphcsPro.h"
#include "Draw.h"
#include <iostream>
using namespace std;
Xe::Xe()
{

}
Xe::Xe(int x, int y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Xe::~Xe()
{

}
void Xe::Ve()
{
	// Khai báo biến tạm để không thay đổi vị trí quân cờ
	int xx = x;
	int yy = y;
	bool zz = z;
	VeNen(x, y);
	COLORREF COLOR;
	Create(x, y, z, COLOR);
	// Vẽ đương chéo "\"
	Line(x - 0.5 * BanKinh, y - 0.6 * BanKinh, x + 0.5 * BanKinh, y + 0.6 * BanKinh, COLOR);
	Line(x - 0.5 * BanKinh + 1, y - 0.6 * BanKinh + 1, x + 0.5 * BanKinh + 1, y + 0.6 * BanKinh + 1, COLOR);
	Line(x - 0.5 * BanKinh - 1, y - 0.6 * BanKinh, x + 0.5 * BanKinh - 1, y + 0.6 * BanKinh, COLOR);
	// Vẽ đương chéo "/"
	Line(x - 0.5 * BanKinh, y + 0.6 * BanKinh, x + 0.5 * BanKinh, y - 0.6 * BanKinh, COLOR);
	Line(x - 0.5 * BanKinh + 1, y + 0.6 * BanKinh + 1, x + 0.5 * BanKinh + 1, y - 0.6 * BanKinh + 1, COLOR);
	Line(x - 0.5 * BanKinh - 1, y + 0.6 * BanKinh - 1, x + 0.5 * BanKinh - 1, y - 0.6 * BanKinh - 1, COLOR);
	// Trả về gia trị bạn đầu cho quân cờ
	x = xx;
	y = yy;
	z = zz;
}
void Xe::DiChuyen()
{
	cout << "Di ngang hay doc tren ban co mien la \ndung bi quan khac can duong tu diem di den diem den." << endl << endl;
	cout << "Cac buoc con Xe co the di chuyen:\n";
	/// Tim cac o phia tren con Phao co the di
	int xx[17] = { -1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1 };
	int yy[17] = { -1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1 };
	int index = 0;
	/// Tim cac o phia tren con Xe co the di
	for (int i = this->y - 1; i >= 0; --i)
	{
		if (IsOk(x, i, this->z))
		{
			if (CheckChampion(x,i,0)) break;
			cout << "( " << this->x + 1 << ", " << i + 1 << " )" << endl;
			xx[index] = this->x;
			yy[index] = i;
			++index;
			if (IsChan(x, i)) break;
		}
		else
		{
			break;
		}
	}
	/// Tim cac o phia duoi con Xe co the di
	for (int i = this->y + 1; i < 10; ++i)
	{
		if (CheckChampion(x, i, 1)) break;
		if (IsOk(x, i, this->z))
		{
			cout << "( " << this->x + 1 << ", " << i + 1 << " )" << endl;
			xx[index] = this->x;
			yy[index] = i;
			++index;
			if (IsChan(x, i)) break;
		}
		else
		{
			break;
		}
		
	}
	// Tim cac o phai ben trai con Xe co the di chuyen
	for (int i = this->x - 1; i >= 0; --i)
	{
		if (IsOk(i, y, this->z))
		{
			cout << "( " << i + 1 << ", " << this->y + 1 << " )" << endl;
			xx[index] = i;
			yy[index] = this->y;
			++index;
			if (IsChan(i, y)) break;
		}
		else
		{
			break;
		}
	}
	/// Tim cac o phia ban  con Xe co the di
	for (int i = this->x + 1; i < 10; ++i)
	{
		if (IsOk(i, y, this->z))
		{
			cout << "( " << i + 1 << ", " << this->y + 1 << " )" << endl;
			xx[index] = i;
			yy[index] = this->y;
			++index;
			if (IsChan(i, y)) break;
		}
		else
		{
			break;
		}
	}
	int iTempX, iTempY;
	bool duoc = 0;
	while (!duoc)
	{
		cout << "Nhap toa doa can di x y (-1 de thoat): ";
		NhapViTriDiChuyen(iTempX, iTempY);
		if (iTempX == -2) break;

		// Xem nhập có đúng cú pháp không?
		if (x < 0 || y < 0 || x > 8 || y > 9)
		{

			cout << "Vui long nhap lai.\n";
			continue;
		}

		// Tìm xem tọa độ vừa nhập có đi được không?
		for (int i = 0; i < 17; ++i)
		{
			if (xx[i] == iTempX && yy[i] == iTempY)
			{
				duoc = 1;
				break;
			}
			if (duoc) break;
		}
		// Nếu nhập đúng vị trí thì cho quân cờ di chuyển và ngược lại
		if (duoc)
		{
			XoaConCo(this->x, this->y);
			Update(this->x, this->y, iTempX, iTempY);
			this->x = iTempX;
			this->y = iTempY;
			this->Ve();
		}
		else
		{
			cout << "Vui long nhap lai.\n";
		}
	}
}