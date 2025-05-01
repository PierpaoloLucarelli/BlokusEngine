import os


class Block:
    def __init__(self, name: str, coords: list[tuple]):
        self.name = name
        self.coords = coords


BLOCK_SET = [
    Block('a', [(0, 0)]),  # I1
    Block('b', [(0, 0), (0, 1)]),  # I2

    Block('c', [(0, 0), (0, 1), (0, -1)]),  # I3
    Block('d', [(0, 0), (1, 0), (0, -1)]),  # L3

    Block('e', [(0, 0), (0, 1), (0, 2), (0, -1)]),  # I4
    Block('f', [(0, 0), (0, -1), (0, 1), (-1, 1)]),  # L4
    Block('g', [(0, 0), (1, 0), (0, 1), (0, -1)]),  # T4
    Block('h', [(0, 0), (1, 0), (0, 1), (1, 1)]),  # O4
    Block('i', [(-1, 0), (0, 0), (0, 1), (1, 1)]),  # Z4

    Block('j', [(0, 0), (0, 1), (0, 2), (0, -1), (0, -2)]),  # I5
    Block('k', [(0, 0), (0, 1), (0, -2), (0, -1), (-1, 1)]),  # L5
    Block('l', [(0, -2), (0, -1), (0, 0), (-1, 0), (-1, 1)]),  # N5
    Block('m', [(0, -1), (-1, 0), (0, 0), (-1, 1), (0, 1)]),  # P5
    Block('n', [(0, 0), (0, 1), (-1, 1), (0, -1), (-1, -1)]),  # C5
    Block('o', [(0, -1), (0, 0), (1, 0), (0, 1), (0, 2)]),  # Y5
    Block('p', [(0, 0), (0, -1), (0, 1), (-1, 1), (1, 1)]),  # T5
    Block('q', [(0, 0), (1, 0), (2, 0), (0, -1), (0, -2)]),  # V5
    Block('r', [(0, 0), (1, 0), (1, 1), (0, -1), (-1, -1)]),  # W5
    Block('s', [(0, 0), (1, 0), (1, 1), (-1, 0), (-1, -1)]),  # Z5
    Block('t', [(-1, -1), (-1, 0), (0, 0), (1, 0), (0, 1)]),  # F5
    Block('u', [(0, 0), (1, 0), (0, 1), (-1, 0), (0, -1)]),  # X5
]


def left(x, y):
    return x - 1, y


def right(x, y):
    return x + 1, y


def up(x, y):
    return x, y - 1


def down(x, y):
    return x, y + 1


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

        self.width, self.height, self.min_x, self.min_y, self.max_x, self.max_y = self.get_size()

    def is_corner(self, xy) -> bool:
        return not (left(*xy) in self.coords and right(*xy) in self.coords or (
                    up(*xy) in self.coords and down(*xy) in self.coords))

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

    def get_size(self) -> tuple[int, int, int, int, int, int]:
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
        return max_x - min_x + 1, max_y - min_y + 1, min_x, min_y, max_x, max_y

def coords_to_js_string(coords) -> str:
    return ','.join([f'[{c[0]}, {c[1]}]' for c in coords])

def coords_to_cpp_string(coords) -> str:
    return ','.join([f'{{{c[0]}, {c[1]}}}' for c in coords])

def corners_to_cpp_str(piece_coords) -> str:
    return "{" + ",".join([str(i) for i, pc in enumerate(piece_coords) if pc["corner"]]) + "}"

def pieces_to_js(pieces: list[Piece]):
    js_str = "export const BLOCK_SET = [\n"
    pieces_str = ""
    for p in pieces:
        rotated_coords = ','.join([f'[{coords_to_js_string(r)}]' for r in make_rotations(p.coords)])
        pieces_str += (
            f"\t new Block('{p.name}', {p.width}, {p.height}, {rotated_coords}),\n")
    return js_str + pieces_str + "];"

def make_rotations(coords: list[tuple]) -> list[list[tuple]]:
    _coords = coords.copy()
    rotated = [_coords.copy()]
    for i in range(3):
        # rotate 90deg
        _coords = [(-c[1], c[0]) for c in _coords]
        rotated.append(_coords.copy())

    flipped = [(-c[0], c[1]) for c in coords]
    rotated.append(flipped.copy())
    for i in range(3):
        # rotate 90deg
        flipped = [(-c[1], c[0]) for c in flipped]
        rotated.append(flipped.copy())
    return rotated




def pieces_to_svg(pieces: list[Piece], block_size_px: int = 15):
    pieces_svg = {}
    for i, p in enumerate(pieces):
        svg_str = f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {p.width * block_size_px} {p.height * block_size_px}" width="{p.width * block_size_px}" height="{p.height * block_size_px}">\n\t'
        for x, y in p.coords:
            adjusted_x = (x - p.min_x) * block_size_px
            adjusted_y = (y - p.min_y) * block_size_px

            svg_str += f"""<rect x="{adjusted_x}" y="{adjusted_y}" width="{block_size_px}" height="{block_size_px}" stroke="black" stroke-width="2"/>\n\t"""
        svg_str += "</svg>"
        pieces_svg[i] = svg_str
    return pieces_svg


def save_svg_to_file(svg_content, filename):
    """Save SVG content to a file"""
    file_path = os.path.join("./src/assets/pieces", f"{str(filename)}.svg")
    with open(file_path, 'w') as f:
        f.write(svg_content)
    print(f"SVG saved to {filename}")

def pieces_to_cpp(pieces: list[Piece]) -> None:
    block_str = []
    for p in pieces:
        rotated_coords = make_rotations(p.coords)
        rotated_pieces = [Piece(coord, i, p.name) for i, coord in enumerate(rotated_coords)]
        rotated_coords_str = ','.join([f'{{{coords_to_cpp_string(rp.coords)}}}' for rp in rotated_pieces])
        corners = corners_to_cpp_str(p.piece_coords)
        block_str.append(f"\tBlock('{p.name}', {len(p.coords)}, {p.width}, {p.height}, {{{rotated_coords_str}}}, {corners})")

    cpp_str = f"Block blocks[21] = {{\n{",\n".join(block_str)}\n}};"
    return cpp_str

    


if __name__ == "__main__":
    pieces = []
    for piece in BLOCK_SET:
        pieces.append(Piece(piece.coords, 0, piece.name))
    cpp_pieces = pieces_to_cpp(pieces)
    print(cpp_pieces)





