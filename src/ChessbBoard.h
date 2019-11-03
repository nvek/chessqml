#ifndef CHESSBBOARD_H
#define CHESSBBOARD_H

#include <QtQuick/QQuickPaintedItem>

class ChessBoard : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
	explicit ChessBoard(QQuickItem *parent = Q_NULLPTR);

	void paint(QPainter* painter) override;




	QString name() const;

public slots:
	void setName(const QString name);
	void move(QPoint oldP, QPoint newP);
	//void move(QString )


signals:
	void nameChanged(const QString name);

private:
	QString _name;
	int		_board[8][8] = {
		{-1, -2, -3, -4, -5, -3, -2, -1},
		{-6, -6, -6, -6, -6, -6, -6, -6},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 1,  2,  3,  4,  5,  3,  2,  1},
		{ 6,  6,  6,  6,  6,  6,  6,  6}
	};

};

#endif // CHESSBBOARD_H
