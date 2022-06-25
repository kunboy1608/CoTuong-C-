#include "Header.h"
#include "GraphcsPro.h"
#include "Draw.h"
#include <iostream>
using namespace std;

Tot::Tot()
{
}
Tot::Tot(int x, int y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Tot::~Tot()
{
}
void Tot::Ve()
{
	
	// Khai báo biến tạm để không thay đổi vị trí quân cờ
	int xx = x;
	int yy = y;
	bool zz = z;
	VeNen(x, y);
	// Vẽ đường cong
	VeConTuongQuan(x, y, z);
	float r = BanKinh * 0.5;
	COLORREF COLOR;
	Create(x, y, z, COLOR);
	
	// Vễ đường thằng ngang
	Line(x + 0.1 * BanKinh, y, x + 0.1 * BanKinh, y + 0.5 * BanKinh, COLOR);
	Line(x + 0.1 * BanKinh - 1, y, x + 0.1 * BanKinh - 1, y + 0.5 * BanKinh, COLOR);
	Line(x + 0.1 * BanKinh + 1, y, x + 0.1 * BanKinh + 1, y + 0.5 * BanKinh, COLOR);

	// Vẽ đường thẳng dọc
	Line(x + 0.3 * BanKinh, y, x - 0.1 * BanKinh, y, COLOR);
	Line(x + 0.3 * BanKinh, y - 1, x - 0.1 * BanKinh, y - 1, COLOR);
	Line(x + 0.3 * BanKinh, y + 1, x - 0.1 * BanKinh, y + 1, COLOR);
	// Trả về gia trị bạn đầu cho quân cờ
	x = xx;
	y = yy;
	z = zz;
}
void Tot::DiChuyen()
{
	cout << "Di 1 o moi nuoc." << endl;
	cout << "Neu tot chua vuot qua song, no chi co the di thang tien." << endl;
	cout << "Khi da vuot song roi, tot co the di ngang 1 nuoc \n hay di thang tien 1 buoc moi nuoc." << endl << endl;
	// Khái báo mảng để chứa các tọa độ mà con tốt có thể đi
	int xx[3] = { -1,-1,-1 };
	int yy[3] = { -1,-1,-1 };
	int index = 0;
	// Xét trường hợp con tốt phe xanh
	if (this->z)
	{
		xx[0] = this->x;
		yy[0] = this->y + 1;
	}
	// Xét trường hợp con tốt phe xanh
	else
	{
		xx[0] = this->x;
		yy[0] = this->y - 1;
	}
	// Xét thêm trường hợp con tốt đã qua sông chưa? Có thể đi ngang
	if (this->QuaSong)
	{
		xx[1] = this->x + 1;
		yy[1] = this->y;
		xx[2] = this->x - 1;
		yy[2] = this->y;

	}
	cout << "Cac toa do con Tot co the di:\n";
	for (int i = 0; i < 3; ++i)
	{
		if (IsOk(xx[i], yy[i], this->z))
		{
			cout << "( " << xx[i] + 1 << ", " << yy[i] + 1 << " )\n";
		}
		else
		{
			xx[i] = -1;
			yy[i] = -1;
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
		for (int i = 0; i < 3; ++i)
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
			if (this->z && this->y >= 5) this->QuaSong = 1;
			if (!this->z && this->y <= 4) this->QuaSong = 1;
		}
		else
		{
			cout << "Vui long nhap lai.\n";
		}
	}
}