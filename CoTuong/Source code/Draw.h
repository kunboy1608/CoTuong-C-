#pragma once
#include <iostream>
#include "GraphcsPro.h"
#include "Header.h"
#include <time.h>
#include <Windows.h>
static int KichThuoc = 80; // Kích thước của mỗi ô cờ 
static int DiemBatDauY = 84; // Tọa độ Y ban đầu của ban cờ
static int DiemBatDauX = 800; // Tọa đọ X ban đầu của bàn cờ
static int BanKinh = 30; // Bán kính của các quân cờ
static HWND myconsole = GetConsoleWindow();
//Get a handle to device context
static HDC mydc = GetDC(myconsole);
//Choose any color
// Hàm xóa làm hình với chỉnh sửa cho phù hợp với chương trình
static void clrscr()
{
	for (int index = 2; index < 50; ++index)
	{
		gotoxy(0, index);
		cout << "                                                                               ";
	}
	gotoxy(0, 2);
}
// Vẽ nền cho quân cờ
static void VeNen(int x, int y)
{
	x = DiemBatDauX + KichThuoc * x;
	y = DiemBatDauY + KichThuoc * y;
	// Vẽ nền trắng cho quân cờ
	Circle2(BanKinh, x, y);
}
// Hàm chuyển đổi và xử lí màu cho các quân cờ
static void Create(int& x, int& y, bool& z, COLORREF& COLOR)
{
	// Tạo màu theo phe của quân cờ
	if (z)
	{
		COLOR = RGB(0, 0, 255);
	}
	else
	{
		COLOR = RGB(255, 0, 0);
	}
	// Chuyển đổi tọa độ bàn cờ thành tọa đọ Pixel
	x = DiemBatDauX + KichThuoc * x;
	y = DiemBatDauY + KichThuoc * y;
}
// Hàm xóa quân cờ
static void XoaConCo(int x, int y)
{
	// Chọn màu thành màu đen
	COLORREF COLOR = RGB(0, 0, 0);
	// Vẽ lại các đường dọc ngang ở ô phía trên gần sông mà không phải ở 2 mép
	if (x != 0 && x != 8 && y == 4)
	{
		x = DiemBatDauX + KichThuoc * x;
		y = DiemBatDauY + KichThuoc * y;
		Circle2(BanKinh, x, y, COLOR);
		Line(x, y - BanKinh, x, y);
		Line(x - BanKinh < DiemBatDauX ? x : x - BanKinh, y, x + BanKinh > DiemBatDauX + 8 * KichThuoc ? x : x + BanKinh, y);
	}
	// Vẽ lại các đường dọc ngang ở ô phía dưới gần sông mà không phải ở 2 mép
	else if (x != 0 && x != 8 && y == 5)
	{
		x = DiemBatDauX + KichThuoc * x;
		y = DiemBatDauY + KichThuoc * y;
		Circle2(BanKinh, x, y, COLOR);
		Line(x, y + BanKinh, x, y);
		Line(x - BanKinh < DiemBatDauX ? x : x - BanKinh, y, x + BanKinh > DiemBatDauX + 8 * KichThuoc ? x : x + BanKinh, y);
	}
	// Vẽ lại các đường ở ô trung tam của cung
	else if (x == 4 && (y == 1 || y == 8))
	{
		x = DiemBatDauX + KichThuoc * x;
		y = DiemBatDauY + KichThuoc * y;
		Circle2(BanKinh, x, y, COLOR);
		Line(x - BanKinh, y, x + BanKinh, y);
		Line(x, y - BanKinh, x, y + BanKinh);
		Line(x - BanKinh, y - BanKinh, x + BanKinh, y + BanKinh);
		Line(x - BanKinh, y + BanKinh, x + BanKinh, y - BanKinh);
	}
	// Xét trường hợp nó nằm ở các ô trong cung cần vẽ lại các đường chéo
	else if (x == 3)
	{
		if (y == 0 || y == 7)
		{
			x = DiemBatDauX + KichThuoc * x;
			y = DiemBatDauY + KichThuoc * y;
			Circle2(BanKinh, x, y, COLOR);
			Line(x, y, x + BanKinh, y + BanKinh);
		}
		else if (y == 2 || y == 9)
		{
			x = DiemBatDauX + KichThuoc * x;
			y = DiemBatDauY + KichThuoc * y;
			Circle2(BanKinh, x, y, COLOR);
			Line(x, y, x + BanKinh, y - BanKinh);
		}
		Line(x, y - BanKinh < DiemBatDauY ? y : y - BanKinh, x, y + BanKinh > DiemBatDauY + 9 * KichThuoc ? y : y + BanKinh);
		Line(x - BanKinh < DiemBatDauX ? x : x - BanKinh, y, x + BanKinh > DiemBatDauX + 8 * KichThuoc ? x : x + BanKinh, y);
	}
	// Xét trường hợp nó nằm ở các ô trong cung cần vẽ lại các đường chéo
	else if (x == 5)
	{
		if (y == 0 || y == 7)
		{
			x = DiemBatDauX + KichThuoc * x;
			y = DiemBatDauY + KichThuoc * y;
			Circle2(BanKinh, x, y, COLOR);
			Line(x, y, x - BanKinh, y + BanKinh);
		}
		else if (y == 2 || y == 9)
		{
			x = DiemBatDauX + KichThuoc * x;
			y = DiemBatDauY + KichThuoc * y;
			Circle2(BanKinh, x, y, COLOR);
			Line(x, y, x - BanKinh, y - BanKinh);
		}
		Line(x, y - BanKinh < DiemBatDauY ? y : y - BanKinh, x, y + BanKinh > DiemBatDauY + 9 * KichThuoc ? y : y + BanKinh);
		Line(x - BanKinh < DiemBatDauX ? x : x - BanKinh, y, x + BanKinh > DiemBatDauX + 8 * KichThuoc ? x : x + BanKinh, y);
	}
	// Vẽ các trường hợp còn lại
	else
	{
		x = DiemBatDauX + KichThuoc * x;
		y = DiemBatDauY + KichThuoc * y;
		Circle2(BanKinh, x, y, COLOR);
		Line(x, y - BanKinh < DiemBatDauY ? y : y - BanKinh, x, y + BanKinh > DiemBatDauY + 9 * KichThuoc ? y : y + BanKinh);
		Line(x - BanKinh < DiemBatDauX ? x : x - BanKinh, y, x + BanKinh > DiemBatDauX + 8 * KichThuoc ? x : x + BanKinh, y);
	}
}
// Hàm vẽ con Tướng, hàm còn dùng lại để vẽ con Tốt
static void VeConTuongQuan(int x, int y, bool z)
{
	float r = BanKinh * 0.5;
	COLORREF COLOR;

	Create(x, y, z, COLOR);

	HalfCircle(r, x + 0.1 * BanKinh, y, COLOR, 0);
	HalfCircle(r - 1, x + 0.1 * BanKinh, y, COLOR, 0);
	HalfCircle(r + 1, x + 0.1 * BanKinh, y, COLOR, 0);

}
// Hàm vẽ quân cờ lúc bắt đầu chơi
static void VeQuanCoBanDau(QuanCo***& ds)
{
	// Vẽ và khời tạo con Xe
	ds[0][0] = new Xe(0, 0, 1);
	ds[0][0]->Ve();
	ds[8][0] = new Xe(8, 0, 1);
	ds[8][0]->Ve();
	ds[0][9] = new Xe(0, 9, 0);
	ds[0][9]->Ve();
	ds[8][9] = new Xe(8, 9, 0);
	ds[8][9]->Ve();
	// Vẽ và khời tạo con Sy
	ds[3][0] = new Sy(3, 0, 1);
	ds[3][0]->Ve();
	ds[5][0] = new Sy(5, 0, 1);
	ds[5][0]->Ve();
	ds[3][9] = new Sy(3, 9, 0);
	ds[3][9]->Ve();
	ds[5][9] = new Sy(5, 9, 0);
	ds[5][9]->Ve();

	// Vẽ và khời tạo con Tướng
	ds[4][0] = new TuongQuan(4, 0, 1);
	ds[4][0]->Ve();
	ds[4][9] = new TuongQuan(4, 9, 0);
	ds[4][9]->Ve();
	// Vẽ và khời tạo con Tượng
	ds[2][0] = new Tuong(2, 0, 1);
	ds[2][0]->Ve();
	ds[6][0] = new Tuong(6, 0, 1);
	ds[6][0]->Ve();
	ds[2][9] = new Tuong(2, 9, 0);
	ds[2][9]->Ve();
	ds[6][9] = new Tuong(6, 9, 0);
	ds[6][9]->Ve();
	// Vẽ và khời tạo con Mã
	ds[1][0] = new Ma(1, 0, 1);
	ds[1][0]->Ve();
	ds[7][0] = new Ma(7, 0, 1);
	ds[7][0]->Ve();
	ds[1][9] = new Ma(1, 9, 0);
	ds[1][9]->Ve();
	ds[7][9] = new Ma(7, 9, 0);
	ds[7][9]->Ve();
	// Vẽ và khời tạo con Tốt
	for (int index = 0; index <= 8; index += 2)
	{
		ds[index][3]= new Tot(index, 3, 1);
		ds[index][3]->Ve();
		ds[index][6]= new Tot(index, 6, 0);
		ds[index][6]->Ve();
	}
	// Vẽ và khời tạo con Pháo
	for (int index = 1; index < 8; index += 6)
	{
		ds[index][2]= new Phao(index, 2, 1);
		ds[index][2]->Ve();
		ds[index][7]= new Phao(index, 7, 0);
		ds[index][7]->Ve();
	}
}
// Hàm xẽ tọa độ của bàn cờ
static void VeToaDo()
{
	/*for (int index = 0; index < 9; ++index)
	{
		gotoxy(88 + index * 9, 0);
		cout << index + 1;
	}*/
	gotoxy(88, 0);
	cout << "1        2        3        4        5        6        7        8        9";
	gotoxy(0, 0);
	for (int index = 0; index < 10; ++index)
	{
		gotoxy(80, 4 + index * 4);
		cout << index + 1;
	}
	gotoxy(0, 0);
}
// Hàm vẽ bàn cờ
static void VeBanCo(QuanCo***& ds)
{
	VeToaDo();
	// Vẽ các đường ngang của bàn cờ
	for (int i = 0; i < 10; ++i)
	{
		Line(DiemBatDauX, DiemBatDauY + KichThuoc * i, DiemBatDauX + 8 * KichThuoc, DiemBatDauY + KichThuoc * i);
	}
	// Do mặt hạn chế của console nên phải vẽ lại 1 lần nữa
	for (int i = 0; i < 10; ++i)
	{
		Line(DiemBatDauX, DiemBatDauY + KichThuoc * i, DiemBatDauX + 8 * KichThuoc, DiemBatDauY + KichThuoc * i);
	}
	// Vẽ các đường dọc của quân cờ
	for (int i = 0; i < 9; ++i)
	{
		Line(DiemBatDauX + KichThuoc * i, DiemBatDauY, DiemBatDauX + KichThuoc * i, DiemBatDauY + 4 * KichThuoc);
		Line(DiemBatDauX + KichThuoc * i, DiemBatDauY + 5 * KichThuoc, DiemBatDauX + KichThuoc * i, DiemBatDauY + 9 * KichThuoc);
	}
	// Vẽ đường chéo từ (3,0) đến (5,2)
	Line(DiemBatDauX + 3 * KichThuoc, DiemBatDauY, DiemBatDauX + 5 * KichThuoc, DiemBatDauY + 2 * KichThuoc);
	// Vẽ đường chéo từ (3,7) đến (5,9)
	Line(DiemBatDauX + 3 * KichThuoc, DiemBatDauY + 7 * KichThuoc, DiemBatDauX + 5 * KichThuoc, DiemBatDauY + 9 * KichThuoc);
	// Vẽ đường chéo từ (3,2) đến (5,0)
	Line(DiemBatDauX + 3 * KichThuoc, DiemBatDauY + 2 * KichThuoc, DiemBatDauX + 5 * KichThuoc, DiemBatDauY);
	// Vẽ đường chéo từ (3,9) đến (5,7)
	Line(DiemBatDauX + 3 * KichThuoc, DiemBatDauY + 9 * KichThuoc, DiemBatDauX + 5 * KichThuoc, DiemBatDauY + 7 * KichThuoc);
	// Vẽ đường mép sông bên trái
	Line(DiemBatDauX, DiemBatDauY + 4 * KichThuoc, DiemBatDauX, DiemBatDauY + 5 * KichThuoc);
	// Vẽ đường mép sông bên phải
	Line(DiemBatDauX + 8 * KichThuoc, DiemBatDauY + 4 * KichThuoc, DiemBatDauX + 8 * KichThuoc, DiemBatDauY + 5 * KichThuoc);
	// Xử lí một số dữ liệu ban đầu cần thiết
	XuLiDuLieuDauVao(ds);
	// Vẽ quân cờ
	VeQuanCoBanDau(ds);
	
}
// Hàm cập nhật vị trí mới cho quân cờ sau khi di chuyển
void Update(int, int, int, int);

