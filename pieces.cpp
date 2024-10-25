#include <vector>
#include <tuple>
using Matrix = std::vector<std::vector<bool>>;

std::vector<std::tuple<int, int>> passPieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> passPieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> passPieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> passPieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<Matrix> passPiece = {

	{
		{1}
	},
	{
		{1}
	},
	{
		{1}
	},
	{
		{1}
	}
};

std::vector<std::tuple<int, int>> sixPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(2,1),
};
std::vector<std::tuple<int, int>> sixPieceCorners = {
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> sixPieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> sixPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,2),
};
std::vector<Matrix> sixPiece = {

	{
		{0,1},
		{1,1},
		{1,1}
	},
	{
		{1,1,0},
		{1,1,1}
	},
	{
		{1,1},
		{1,1},
		{1,0}
	},
	{
		{1,1,1},
		{0,1,1}
	}
};

std::vector<std::tuple<int, int>> twoPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,1),
};
std::vector<std::tuple<int, int>> twoPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> twoPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> twoPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,0),
};
std::vector<Matrix> twoPiece = {

	{
		{1,1}
	},
	{
		{1},
		{1}
	},
	{
		{1,1}
	},
	{
		{1},
		{1}
	}
};

std::vector<std::tuple<int, int>> threePieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,2),
};
std::vector<std::tuple<int, int>> threePieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(2,0),
};
std::vector<std::tuple<int, int>> threePieceCorners = {
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> threePieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,0),
};
std::vector<Matrix> threePiece = {

	{
		{1,1,1}
	},
	{
		{1},
		{1},
		{1}
	},
	{
		{1,1,1}
	},
	{
		{1},
		{1},
		{1}
	}
};

std::vector<std::tuple<int, int>> mediumlPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(2,1),
};
std::vector<std::tuple<int, int>> mediumlPieceCorners = {
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> mediumlPieceCorners = {
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> mediumlPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,2),
};
std::vector<Matrix> mediumlPiece = {

	{
		{1,0},
		{1,0},
		{1,1}
	},
	{
		{1,1,1},
		{1,0,0}
	},
	{
		{1,1},
		{0,1},
		{0,1}
	},
	{
		{0,0,1},
		{1,1,1}
	}
};

std::vector<std::tuple<int, int>> diggerPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(3,0),
};
std::vector<std::tuple<int, int>> diggerPieceCorners = {
	std::tuple<int, int>(1,3),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> diggerPieceCorners = {
	std::tuple<int, int>(3,0),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,1),
};
std::vector<std::tuple<int, int>> diggerPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(1,3),
};
std::vector<Matrix> diggerPiece = {

	{
		{0,1},
		{0,1},
		{1,1},
		{1,0}
	},
	{
		{1,1,0,0},
		{0,1,1,1}
	},
	{
		{0,1},
		{1,1},
		{1,0},
		{1,0}
	},
	{
		{1,1,1,0},
		{0,0,1,1}
	}
};

std::vector<std::tuple<int, int>> longlPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(3,0),
	std::tuple<int, int>(3,1),
};
std::vector<std::tuple<int, int>> longlPieceCorners = {
	std::tuple<int, int>(0,3),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> longlPieceCorners = {
	std::tuple<int, int>(3,1),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> longlPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,3),
	std::tuple<int, int>(0,3),
};
std::vector<Matrix> longlPiece = {

	{
		{1,0},
		{1,0},
		{1,0},
		{1,1}
	},
	{
		{1,1,1,1},
		{1,0,0,0}
	},
	{
		{1,1},
		{0,1},
		{0,1},
		{0,1}
	},
	{
		{0,0,0,1},
		{1,1,1,1}
	}
};

std::vector<std::tuple<int, int>> uPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,2),
};
std::vector<std::tuple<int, int>> uPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(2,0),
};
std::vector<std::tuple<int, int>> uPieceCorners = {
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> uPieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(0,1),
};
std::vector<Matrix> uPiece = {

	{
		{1,0,1},
		{1,1,1}
	},
	{
		{1,1},
		{1,0},
		{1,1}
	},
	{
		{1,1,1},
		{1,0,1}
	},
	{
		{1,1},
		{0,1},
		{1,1}
	}
};

std::vector<std::tuple<int, int>> iPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,4),
};
std::vector<std::tuple<int, int>> iPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(4,0),
};
std::vector<std::tuple<int, int>> iPieceCorners = {
	std::tuple<int, int>(0,4),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> iPieceCorners = {
	std::tuple<int, int>(4,0),
	std::tuple<int, int>(0,0),
};
std::vector<Matrix> iPiece = {

	{
		{1,1,1,1,1}
	},
	{
		{1},
		{1},
		{1},
		{1},
		{1}
	},
	{
		{1,1,1,1,1}
	},
	{
		{1},
		{1},
		{1},
		{1},
		{1}
	}
};

std::vector<std::tuple<int, int>> oPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,1),
};
std::vector<std::tuple<int, int>> oPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> oPieceCorners = {
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> oPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,1),
};
std::vector<Matrix> oPiece = {

	{
		{1,1},
		{1,1}
	},
	{
		{1,1},
		{1,1}
	},
	{
		{1,1},
		{1,1}
	},
	{
		{1,1},
		{1,1}
	}
};

std::vector<std::tuple<int, int>> crossPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(2,1),
};
std::vector<std::tuple<int, int>> crossPieceCorners = {
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> crossPieceCorners = {
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,1),
};
std::vector<std::tuple<int, int>> crossPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,2),
};
std::vector<Matrix> crossPiece = {

	{
		{0,1,0},
		{1,1,1},
		{0,1,0}
	},
	{
		{0,1,0},
		{1,1,1},
		{0,1,0}
	},
	{
		{0,1,0},
		{1,1,1},
		{0,1,0}
	},
	{
		{0,1,0},
		{1,1,1},
		{0,1,0}
	}
};

std::vector<std::tuple<int, int>> bigCornerPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(2,2),
};
std::vector<std::tuple<int, int>> bigCornerPieceCorners = {
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(2,2),
	std::tuple<int, int>(2,0),
};
std::vector<std::tuple<int, int>> bigCornerPieceCorners = {
	std::tuple<int, int>(2,2),
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> bigCornerPieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,2),
};
std::vector<Matrix> bigCornerPiece = {

	{
		{1,0,0},
		{1,0,0},
		{1,1,1}
	},
	{
		{1,1,1},
		{1,0,0},
		{1,0,0}
	},
	{
		{1,1,1},
		{0,0,1},
		{0,0,1}
	},
	{
		{0,0,1},
		{0,0,1},
		{1,1,1}
	}
};

std::vector<std::tuple<int, int>> tPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,2),
};
std::vector<std::tuple<int, int>> tPieceCorners = {
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(2,0),
};
std::vector<std::tuple<int, int>> tPieceCorners = {
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> tPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(0,1),
};
std::vector<Matrix> tPiece = {

	{
		{0,1,0},
		{1,1,1}
	},
	{
		{1,0},
		{1,1},
		{1,0}
	},
	{
		{1,1,1},
		{0,1,0}
	},
	{
		{0,1},
		{1,1},
		{0,1}
	}
};

std::vector<std::tuple<int, int>> smallCornerPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,1),
};
std::vector<std::tuple<int, int>> smallCornerPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> smallCornerPieceCorners = {
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> smallCornerPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,1),
};
std::vector<Matrix> smallCornerPiece = {

	{
		{1,0},
		{1,1}
	},
	{
		{1,1},
		{1,0}
	},
	{
		{1,1},
		{0,1}
	},
	{
		{0,1},
		{1,1}
	}
};

std::vector<std::tuple<int, int>> dinoPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(2,1),
};
std::vector<std::tuple<int, int>> dinoPieceCorners = {
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> dinoPieceCorners = {
	std::tuple<int, int>(2,2),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,1),
};
std::vector<std::tuple<int, int>> dinoPieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,2),
};
std::vector<Matrix> dinoPiece = {

	{
		{1,1,0},
		{0,1,1},
		{0,1,0}
	},
	{
		{0,0,1},
		{1,1,1},
		{0,1,0}
	},
	{
		{0,1,0},
		{1,1,0},
		{0,1,1}
	},
	{
		{0,1,0},
		{1,1,1},
		{1,0,0}
	}
};

std::vector<std::tuple<int, int>> singlePieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> singlePieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> singlePieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> singlePieceCorners = {
	std::tuple<int, int>(0,0),
};
std::vector<Matrix> singlePiece = {

	{
		{1}
	},
	{
		{1}
	},
	{
		{1}
	},
	{
		{1}
	}
};

std::vector<std::tuple<int, int>> zigzagPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(2,2),
};
std::vector<std::tuple<int, int>> zigzagPieceCorners = {
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(2,0),
};
std::vector<std::tuple<int, int>> zigzagPieceCorners = {
	std::tuple<int, int>(2,2),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> zigzagPieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(2,1),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,2),
};
std::vector<Matrix> zigzagPiece = {

	{
		{1,0,0},
		{1,1,0},
		{0,1,1}
	},
	{
		{0,1,1},
		{1,1,0},
		{1,0,0}
	},
	{
		{1,1,0},
		{0,1,1},
		{0,0,1}
	},
	{
		{0,0,1},
		{0,1,1},
		{1,1,0}
	}
};

std::vector<std::tuple<int, int>> zPieceCorners = {
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(1,2),
};
std::vector<std::tuple<int, int>> zPieceCorners = {
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(2,0),
};
std::vector<std::tuple<int, int>> zPieceCorners = {
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> zPieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(0,1),
};
std::vector<Matrix> zPiece = {

	{
		{1,1,0},
		{0,1,1}
	},
	{
		{0,1},
		{1,1},
		{1,0}
	},
	{
		{1,1,0},
		{0,1,1}
	},
	{
		{0,1},
		{1,1},
		{1,0}
	}
};

std::vector<std::tuple<int, int>> snakePieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(2,2),
};
std::vector<std::tuple<int, int>> snakePieceCorners = {
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(2,0),
};
std::vector<std::tuple<int, int>> snakePieceCorners = {
	std::tuple<int, int>(2,2),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> snakePieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,2),
};
std::vector<Matrix> snakePiece = {

	{
		{1,1,0},
		{0,1,0},
		{0,1,1}
	},
	{
		{0,0,1},
		{1,1,1},
		{1,0,0}
	},
	{
		{1,1,0},
		{0,1,0},
		{0,1,1}
	},
	{
		{0,0,1},
		{1,1,1},
		{1,0,0}
	}
};

std::vector<std::tuple<int, int>> submarinePieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,1),
	std::tuple<int, int>(3,0),
};
std::vector<std::tuple<int, int>> submarinePieceCorners = {
	std::tuple<int, int>(0,3),
	std::tuple<int, int>(1,2),
	std::tuple<int, int>(0,0),
};
std::vector<std::tuple<int, int>> submarinePieceCorners = {
	std::tuple<int, int>(3,1),
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,1),
};
std::vector<std::tuple<int, int>> submarinePieceCorners = {
	std::tuple<int, int>(1,0),
	std::tuple<int, int>(0,1),
	std::tuple<int, int>(1,3),
};
std::vector<Matrix> submarinePiece = {

	{
		{1,0},
		{1,1},
		{1,0},
		{1,0}
	},
	{
		{1,1,1,1},
		{0,0,1,0}
	},
	{
		{0,1},
		{0,1},
		{1,1},
		{0,1}
	},
	{
		{0,1,0,0},
		{1,1,1,1}
	}
};

std::vector<std::tuple<int, int>> bigtPieceCorners = {
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(2,1),
};
std::vector<std::tuple<int, int>> bigtPieceCorners = {
	std::tuple<int, int>(0,2),
	std::tuple<int, int>(2,2),
	std::tuple<int, int>(1,0),
};
std::vector<std::tuple<int, int>> bigtPieceCorners = {
	std::tuple<int, int>(2,2),
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,1),
};
std::vector<std::tuple<int, int>> bigtPieceCorners = {
	std::tuple<int, int>(2,0),
	std::tuple<int, int>(0,0),
	std::tuple<int, int>(1,2),
};
std::vector<Matrix> bigtPiece = {

	{
		{1,1,1},
		{0,1,0},
		{0,1,0}
	},
	{
		{0,0,1},
		{1,1,1},
		{0,0,1}
	},
	{
		{0,1,0},
		{0,1,0},
		{1,1,1}
	},
	{
		{1,0,0},
		{1,1,1},
		{1,0,0}
	}
};

