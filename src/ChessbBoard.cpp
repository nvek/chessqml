#include "ChessbBoard.h"
#include <QPainter>

ChessBoard::ChessBoard(QQuickItem *parent) :
	QQuickPaintedItem (parent)
{

}



void ChessBoard::paint(QPainter* painter)
{
	// как будет смотреться? если сделать массив указателей на обьексты фигур?
	auto getFigure = [](int type) ->QImage
	{
		switch (type)
		{
		case -1:
			return QImage(QImage(":/figure/rook.png"));
		case -2:
			return QImage(QImage(":/figure/knight.png"));
		case -3:
			return QImage(QImage(":/figure/bishop.png"));
		case -4:
			return QImage(QImage(":/figure/queen.png"));
		case -5:
			return QImage(QImage(":/figure/king.png"));
		case -6:
			return QImage(QImage(":/figure/pawn.png"));
		default:
			return QImage();
		}
	};

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			// доска
			if((i + j) % 2 == 0)
				painter->fillRect(QRectF(i*32, j*32, 32, 32), QBrush(Qt::white));
			else
				painter->fillRect(QRectF(i*32, j*32, 32, 32), QBrush(Qt::gray));

			// фигура
			painter->drawImage(QRectF(i*32, j*32, 32, 32), getFigure(_board[j][i]));
		}

	}
}

void ChessBoard::move(QPoint oldP, QPoint newP)
{
	// получил координаты клеток от куда куда
	auto toKoord = [](qreal pos)->int {
		return pos / 32;
	};
	int oldX = toKoord(oldP.rx());
	int oldY = toKoord(oldP.ry());
	int newX = toKoord(newP.rx());
	int newY = toKoord(newP.ry());

	_board[newY][newX] = _board[oldY][oldX];
	_board[oldY][oldX] = 0;
	QQuickPaintedItem::update();
}


void ChessBoard::setName(const QString name)
{
	_name = name;
}

QString ChessBoard::name() const
{
	return _name;
}
