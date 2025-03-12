class Block:
    def __init__(self, name: str, coords: list[tuple]):
        self.name = name
        self.coords = coords


BLOCK_SET = [
  Block('a', [(0,0)]), # I1
  Block('b', [(0,0), (0,1)]), # I2

  Block('c', [(0,0), (0,1), (0,-1)]), # I3
  Block('d', [(0,0), (1,0), (0,-1)]), # L3

  Block('e', [(0,0), (0,1), (0,2), (0,-1)]), # I4
  Block('f', [(0,0), (0,-1), (0,1), (-1,1)]), # L4
  Block('g', [(0,0), (1,0), (0,1), (0,-1)]), # T4
  Block('h', [(0,0), (1,0), (0,1), (1,1)]), # O4
  Block('i', [(-1,0), (0,0), (0,1), (1,1)]), # Z4

  Block('j', [(0,0), (0,1), (0,2), (0,-1), (0,-2)]), # I5
  Block('k', [(0,0), (0,1), (0,-2), (0,-1), (-1,1)]), # L5
  Block('l', [(0,-2), (0,-1), (0,0), (-1,0), (-1,1)]), # N5
  Block('m', [(0,-1), (-1,0), (0,0), (-1,1), (0,1)]), # P5
  Block('n', [(0,0), (0,1), (-1,1), (0,-1), (-1,-1)]), # C5
  Block('o', [(0,-1), (0,0), (1,0), (0,1), (0,2)]), # Y5
  Block('p', [(0,0), (0,-1), (0,1), (-1,1), (1,1)]), # T5
  Block('q', [(0,0), (1,0), (2,0), (0,-1), (0,-2)]), # V5
  Block('r', [(0,0), (1,0), (1,1), (0,-1), (-1,-1)]), # W5
  Block('s', [(0,0), (1,0), (1,1), (-1,0), (-1,-1)]), # Z5
  Block('t', [(-1,-1), (-1,0), (0,0), (1,0), (0,1)]), # F5
  Block('u', [(0,0), (1,0), (0,1), (-1,0), (0,-1)]), # X5
]

def left(x, y):
    return x-1, y

def right(x, y):
    return x+1, y

def up(x,y):
    return x, y-1

def down(x,y):
    return x, y+1



class Piece:
    def __init__(self, coords: list[tuple], orientation: int, name: str):
        self.coords = coords
        self.orientation = orientation
        self.name = name
        self.piece_coords = [
            {
                "coord": xy,
                "corner": self.is_corner(xy),
                "oriented": {
                    "nw": self.is_oriented(xy, "nw"),
                    "ne": self.is_oriented(xy, "ne"),
                    "sw": self.is_oriented(xy, "sw"),
                    "se": self.is_oriented(xy, "se"),
                } if self.is_corner(xy) else None
            }
            for xy in coords
        ]

        self.width, self.height = self.get_size()

    def is_corner(self, xy) -> bool:
        return not (left(*xy) in self.coords and right(*xy) in self.coords or (up(*xy) in self.coords and down(*xy) in self.coords))

    def is_oriented(self, xy: tuple, orient: str) -> bool:
        match orient:
            case "nw":
                return not left(*xy) in self.coords and not up(*xy) in self.coords
            case "ne":
                return not right(*xy) in self.coords and not up(*xy) in self.coords
            case "sw":
                return not left(*xy) in self.coords and not down(*xy) in self.coords
            case "se":
                return not right(*xy) in self.coords and not down(*xy) in self.coords

    def get_size(self) -> tuple[int, int]:
        max_y = -10
        min_y = 10
        max_x = -10
        min_x = 10
        for x, y in self.coords:
            if y > max_y:
                max_y = y
            if y < min_y:
                min_y = y
            if x > max_x:
                max_x = x
            if x < min_x:
                min_x = x
        return max_x - min_x + 1, max_y - min_y + 1


def pieces_to_js(pieces: list[Piece]):
    js_str = "export const BLOCK_SET = [\n"
    pieces_str = ""
    for p in pieces:
        pieces_str += (f"\t new Block('{p.name}', {p.width}, {p.height}, {','.join([f'[{c[0]}, {c[1]}]' for c in p.coords])}),\n")
    return js_str + pieces_str + "];"



if __name__ == "__main__":
    pieces = []
    for piece in BLOCK_SET:
        pieces.append(Piece(piece.coords, 0, piece.name))
    print(pieces_to_js(pieces))
    print(pieces)




            
