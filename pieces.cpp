#include <vector>
#include <tuple>
using Matrix = std::vector<std::vector<bool>>;

using MatrixCorner = std::vector<std::tuple<int, int>>;

std::vector<MatrixCorner> passPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(0,0),
	},
};
std::vector<Matrix> passPieceShape = {

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

BlokusPiece passPiece = BlokusPiece(passPieceShape, false, "passPiece", 1, passPieceCornerBlocks);

std::vector<MatrixCorner> sixPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(2,1),
	},
	{
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,2),
	},
};
std::vector<Matrix> sixPieceShape = {

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

BlokusPiece sixPiece = BlokusPiece(sixPieceShape, false, "sixPiece", 5, sixPieceCornerBlocks);

std::vector<MatrixCorner> twoPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,1),
	},
	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,0),
	},
};
std::vector<Matrix> twoPieceShape = {

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

BlokusPiece twoPiece = BlokusPiece(twoPieceShape, false, "twoPiece", 2, twoPieceCornerBlocks);

std::vector<MatrixCorner> threePieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,2),
	},
	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(2,0),
	},
	{
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,0),
	},
};
std::vector<Matrix> threePieceShape = {

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

BlokusPiece threePiece = BlokusPiece(threePieceShape, false, "threePiece", 3, threePieceCornerBlocks);

std::vector<MatrixCorner> mediumlPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(2,1),
	},
	{
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,2),
	},
};
std::vector<Matrix> mediumlPieceShape = {

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

BlokusPiece mediumlPiece = BlokusPiece(mediumlPieceShape, false, "mediumlPiece", 4, mediumlPieceCornerBlocks);

std::vector<MatrixCorner> diggerPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(3,0),
	},
	{
		std::tuple<int, int>(1,3),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(3,0),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,1),
	},
	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(1,3),
	},
};
std::vector<Matrix> diggerPieceShape = {

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

BlokusPiece diggerPiece = BlokusPiece(diggerPieceShape, false, "diggerPiece", 5, diggerPieceCornerBlocks);

std::vector<MatrixCorner> longlPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(3,0),
		std::tuple<int, int>(3,1),
	},
	{
		std::tuple<int, int>(0,3),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(3,1),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,3),
		std::tuple<int, int>(0,3),
	},
};
std::vector<Matrix> longlPieceShape = {

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

BlokusPiece longlPiece = BlokusPiece(longlPieceShape, false, "longlPiece", 5, longlPieceCornerBlocks);

std::vector<MatrixCorner> uPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,2),
	},
	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(2,0),
	},
	{
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(0,1),
	},
};
std::vector<Matrix> uPieceShape = {

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

BlokusPiece uPiece = BlokusPiece(uPieceShape, false, "uPiece", 5, uPieceCornerBlocks);

std::vector<MatrixCorner> iPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,4),
	},
	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(4,0),
	},
	{
		std::tuple<int, int>(0,4),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(4,0),
		std::tuple<int, int>(0,0),
	},
};
std::vector<Matrix> iPieceShape = {

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

BlokusPiece iPiece = BlokusPiece(iPieceShape, false, "iPiece", 5, iPieceCornerBlocks);

std::vector<MatrixCorner> oPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,1),
	},
	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,1),
	},
};
std::vector<Matrix> oPieceShape = {

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

BlokusPiece oPiece = BlokusPiece(oPieceShape, false, "oPiece", 4, oPieceCornerBlocks);

std::vector<MatrixCorner> crossPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(2,1),
	},
	{
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,1),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,2),
	},
};
std::vector<Matrix> crossPieceShape = {

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

BlokusPiece crossPiece = BlokusPiece(crossPieceShape, false, "crossPiece", 5, crossPieceCornerBlocks);

std::vector<MatrixCorner> bigCornerPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(2,2),
	},
	{
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(2,2),
		std::tuple<int, int>(2,0),
	},
	{
		std::tuple<int, int>(2,2),
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,2),
	},
};
std::vector<Matrix> bigCornerPieceShape = {

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

BlokusPiece bigCornerPiece = BlokusPiece(bigCornerPieceShape, false, "bigCornerPiece", 5, bigCornerPieceCornerBlocks);

std::vector<MatrixCorner> tPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,2),
	},
	{
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(2,0),
	},
	{
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(0,1),
	},
};
std::vector<Matrix> tPieceShape = {

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

BlokusPiece tPiece = BlokusPiece(tPieceShape, false, "tPiece", 4, tPieceCornerBlocks);

std::vector<MatrixCorner> smallCornerPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,1),
	},
	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,1),
	},
};
std::vector<Matrix> smallCornerPieceShape = {

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

BlokusPiece smallCornerPiece = BlokusPiece(smallCornerPieceShape, false, "smallCornerPiece", 3, smallCornerPieceCornerBlocks);

std::vector<MatrixCorner> dinoPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(2,1),
	},
	{
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(2,2),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,1),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,2),
	},
};
std::vector<Matrix> dinoPieceShape = {

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

BlokusPiece dinoPiece = BlokusPiece(dinoPieceShape, false, "dinoPiece", 5, dinoPieceCornerBlocks);

std::vector<MatrixCorner> singlePieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(0,0),
	},
};
std::vector<Matrix> singlePieceShape = {

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

BlokusPiece singlePiece = BlokusPiece(singlePieceShape, false, "singlePiece", 1, singlePieceCornerBlocks);

std::vector<MatrixCorner> zigzagPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(2,2),
	},
	{
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(2,0),
	},
	{
		std::tuple<int, int>(2,2),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(2,1),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,2),
	},
};
std::vector<Matrix> zigzagPieceShape = {

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

BlokusPiece zigzagPiece = BlokusPiece(zigzagPieceShape, false, "zigzagPiece", 5, zigzagPieceCornerBlocks);

std::vector<MatrixCorner> zPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(1,2),
	},
	{
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(2,0),
	},
	{
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(0,1),
	},
};
std::vector<Matrix> zPieceShape = {

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

BlokusPiece zPiece = BlokusPiece(zPieceShape, false, "zPiece", 4, zPieceCornerBlocks);

std::vector<MatrixCorner> snakePieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(2,2),
	},
	{
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(2,0),
	},
	{
		std::tuple<int, int>(2,2),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,2),
	},
};
std::vector<Matrix> snakePieceShape = {

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

BlokusPiece snakePiece = BlokusPiece(snakePieceShape, false, "snakePiece", 5, snakePieceCornerBlocks);

std::vector<MatrixCorner> submarinePieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,1),
		std::tuple<int, int>(3,0),
	},
	{
		std::tuple<int, int>(0,3),
		std::tuple<int, int>(1,2),
		std::tuple<int, int>(0,0),
	},
	{
		std::tuple<int, int>(3,1),
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,1),
	},
	{
		std::tuple<int, int>(1,0),
		std::tuple<int, int>(0,1),
		std::tuple<int, int>(1,3),
	},
};
std::vector<Matrix> submarinePieceShape = {

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

BlokusPiece submarinePiece = BlokusPiece(submarinePieceShape, false, "submarinePiece", 5, submarinePieceCornerBlocks);

std::vector<MatrixCorner> bigtPieceCornerBlocks = {

	{
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(2,1),
	},
	{
		std::tuple<int, int>(0,2),
		std::tuple<int, int>(2,2),
		std::tuple<int, int>(1,0),
	},
	{
		std::tuple<int, int>(2,2),
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,1),
	},
	{
		std::tuple<int, int>(2,0),
		std::tuple<int, int>(0,0),
		std::tuple<int, int>(1,2),
	},
};
std::vector<Matrix> bigtPieceShape = {

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

BlokusPiece bigtPiece = BlokusPiece(bigtPieceShape, false, "bigtPiece", 5, bigtPieceCornerBlocks);

