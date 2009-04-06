
#include <schroedinger/schrotables.h>

const int schro_table_unpack_sint[256][17] = {
  /*   0 */ { 0, },
  /*   1 */ { 0, },
  /*   2 */ { 1, 7, 8, },
  /*   3 */ { 1, -7, 8, },
  /*   4 */ { 0, },
  /*   5 */ { 0, },
  /*   6 */ { 1, 8, 8, },
  /*   7 */ { 1, -8, 8, },
  /*   8 */ { 1, 3, 6, },
  /*   9 */ { 1, 3, 6, },
  /*  10 */ { 2, 3, 6, 0, 7, },
  /*  11 */ { 3, 3, 6, 0, 7, 0, 8, },
  /*  12 */ { 1, -3, 6, },
  /*  13 */ { 1, -3, 6, },
  /*  14 */ { 2, -3, 6, 0, 7, },
  /*  15 */ { 3, -3, 6, 0, 7, 0, 8, },
  /*  16 */ { 0, },
  /*  17 */ { 0, },
  /*  18 */ { 1, 9, 8, },
  /*  19 */ { 1, -9, 8, },
  /*  20 */ { 0, },
  /*  21 */ { 0, },
  /*  22 */ { 1, 10, 8, },
  /*  23 */ { 1, -10, 8, },
  /*  24 */ { 1, 4, 6, },
  /*  25 */ { 1, 4, 6, },
  /*  26 */ { 2, 4, 6, 0, 7, },
  /*  27 */ { 3, 4, 6, 0, 7, 0, 8, },
  /*  28 */ { 1, -4, 6, },
  /*  29 */ { 1, -4, 6, },
  /*  30 */ { 2, -4, 6, 0, 7, },
  /*  31 */ { 3, -4, 6, 0, 7, 0, 8, },
  /*  32 */ { 1, 1, 4, },
  /*  33 */ { 1, 1, 4, },
  /*  34 */ { 2, 1, 4, 1, 8, },
  /*  35 */ { 2, 1, 4, -1, 8, },
  /*  36 */ { 1, 1, 4, },
  /*  37 */ { 1, 1, 4, },
  /*  38 */ { 2, 1, 4, 2, 8, },
  /*  39 */ { 2, 1, 4, -2, 8, },
  /*  40 */ { 2, 1, 4, 0, 5, },
  /*  41 */ { 2, 1, 4, 0, 5, },
  /*  42 */ { 2, 1, 4, 0, 5, },
  /*  43 */ { 2, 1, 4, 0, 5, },
  /*  44 */ { 3, 1, 4, 0, 5, 0, 6, },
  /*  45 */ { 3, 1, 4, 0, 5, 0, 6, },
  /*  46 */ { 4, 1, 4, 0, 5, 0, 6, 0, 7, },
  /*  47 */ { 5, 1, 4, 0, 5, 0, 6, 0, 7, 0, 8, },
  /*  48 */ { 1, -1, 4, },
  /*  49 */ { 1, -1, 4, },
  /*  50 */ { 2, -1, 4, 1, 8, },
  /*  51 */ { 2, -1, 4, -1, 8, },
  /*  52 */ { 1, -1, 4, },
  /*  53 */ { 1, -1, 4, },
  /*  54 */ { 2, -1, 4, 2, 8, },
  /*  55 */ { 2, -1, 4, -2, 8, },
  /*  56 */ { 2, -1, 4, 0, 5, },
  /*  57 */ { 2, -1, 4, 0, 5, },
  /*  58 */ { 2, -1, 4, 0, 5, },
  /*  59 */ { 2, -1, 4, 0, 5, },
  /*  60 */ { 3, -1, 4, 0, 5, 0, 6, },
  /*  61 */ { 3, -1, 4, 0, 5, 0, 6, },
  /*  62 */ { 4, -1, 4, 0, 5, 0, 6, 0, 7, },
  /*  63 */ { 5, -1, 4, 0, 5, 0, 6, 0, 7, 0, 8, },
  /*  64 */ { 0, },
  /*  65 */ { 0, },
  /*  66 */ { 1, 11, 8, },
  /*  67 */ { 1, -11, 8, },
  /*  68 */ { 0, },
  /*  69 */ { 0, },
  /*  70 */ { 1, 12, 8, },
  /*  71 */ { 1, -12, 8, },
  /*  72 */ { 1, 5, 6, },
  /*  73 */ { 1, 5, 6, },
  /*  74 */ { 2, 5, 6, 0, 7, },
  /*  75 */ { 3, 5, 6, 0, 7, 0, 8, },
  /*  76 */ { 1, -5, 6, },
  /*  77 */ { 1, -5, 6, },
  /*  78 */ { 2, -5, 6, 0, 7, },
  /*  79 */ { 3, -5, 6, 0, 7, 0, 8, },
  /*  80 */ { 0, },
  /*  81 */ { 0, },
  /*  82 */ { 1, 13, 8, },
  /*  83 */ { 1, -13, 8, },
  /*  84 */ { 0, },
  /*  85 */ { 0, },
  /*  86 */ { 1, 14, 8, },
  /*  87 */ { 1, -14, 8, },
  /*  88 */ { 1, 6, 6, },
  /*  89 */ { 1, 6, 6, },
  /*  90 */ { 2, 6, 6, 0, 7, },
  /*  91 */ { 3, 6, 6, 0, 7, 0, 8, },
  /*  92 */ { 1, -6, 6, },
  /*  93 */ { 1, -6, 6, },
  /*  94 */ { 2, -6, 6, 0, 7, },
  /*  95 */ { 3, -6, 6, 0, 7, 0, 8, },
  /*  96 */ { 1, 2, 4, },
  /*  97 */ { 1, 2, 4, },
  /*  98 */ { 2, 2, 4, 1, 8, },
  /*  99 */ { 2, 2, 4, -1, 8, },
  /* 100 */ { 1, 2, 4, },
  /* 101 */ { 1, 2, 4, },
  /* 102 */ { 2, 2, 4, 2, 8, },
  /* 103 */ { 2, 2, 4, -2, 8, },
  /* 104 */ { 2, 2, 4, 0, 5, },
  /* 105 */ { 2, 2, 4, 0, 5, },
  /* 106 */ { 2, 2, 4, 0, 5, },
  /* 107 */ { 2, 2, 4, 0, 5, },
  /* 108 */ { 3, 2, 4, 0, 5, 0, 6, },
  /* 109 */ { 3, 2, 4, 0, 5, 0, 6, },
  /* 110 */ { 4, 2, 4, 0, 5, 0, 6, 0, 7, },
  /* 111 */ { 5, 2, 4, 0, 5, 0, 6, 0, 7, 0, 8, },
  /* 112 */ { 1, -2, 4, },
  /* 113 */ { 1, -2, 4, },
  /* 114 */ { 2, -2, 4, 1, 8, },
  /* 115 */ { 2, -2, 4, -1, 8, },
  /* 116 */ { 1, -2, 4, },
  /* 117 */ { 1, -2, 4, },
  /* 118 */ { 2, -2, 4, 2, 8, },
  /* 119 */ { 2, -2, 4, -2, 8, },
  /* 120 */ { 2, -2, 4, 0, 5, },
  /* 121 */ { 2, -2, 4, 0, 5, },
  /* 122 */ { 2, -2, 4, 0, 5, },
  /* 123 */ { 2, -2, 4, 0, 5, },
  /* 124 */ { 3, -2, 4, 0, 5, 0, 6, },
  /* 125 */ { 3, -2, 4, 0, 5, 0, 6, },
  /* 126 */ { 4, -2, 4, 0, 5, 0, 6, 0, 7, },
  /* 127 */ { 5, -2, 4, 0, 5, 0, 6, 0, 7, 0, 8, },
  /* 128 */ { 1, 0, 1, },
  /* 129 */ { 1, 0, 1, },
  /* 130 */ { 1, 0, 1, },
  /* 131 */ { 1, 0, 1, },
  /* 132 */ { 2, 0, 1, 3, 7, },
  /* 133 */ { 3, 0, 1, 3, 7, 0, 8, },
  /* 134 */ { 2, 0, 1, -3, 7, },
  /* 135 */ { 3, 0, 1, -3, 7, 0, 8, },
  /* 136 */ { 1, 0, 1, },
  /* 137 */ { 1, 0, 1, },
  /* 138 */ { 1, 0, 1, },
  /* 139 */ { 1, 0, 1, },
  /* 140 */ { 2, 0, 1, 4, 7, },
  /* 141 */ { 3, 0, 1, 4, 7, 0, 8, },
  /* 142 */ { 2, 0, 1, -4, 7, },
  /* 143 */ { 3, 0, 1, -4, 7, 0, 8, },
  /* 144 */ { 2, 0, 1, 1, 5, },
  /* 145 */ { 2, 0, 1, 1, 5, },
  /* 146 */ { 2, 0, 1, 1, 5, },
  /* 147 */ { 2, 0, 1, 1, 5, },
  /* 148 */ { 3, 0, 1, 1, 5, 0, 6, },
  /* 149 */ { 3, 0, 1, 1, 5, 0, 6, },
  /* 150 */ { 4, 0, 1, 1, 5, 0, 6, 0, 7, },
  /* 151 */ { 5, 0, 1, 1, 5, 0, 6, 0, 7, 0, 8, },
  /* 152 */ { 2, 0, 1, -1, 5, },
  /* 153 */ { 2, 0, 1, -1, 5, },
  /* 154 */ { 2, 0, 1, -1, 5, },
  /* 155 */ { 2, 0, 1, -1, 5, },
  /* 156 */ { 3, 0, 1, -1, 5, 0, 6, },
  /* 157 */ { 3, 0, 1, -1, 5, 0, 6, },
  /* 158 */ { 4, 0, 1, -1, 5, 0, 6, 0, 7, },
  /* 159 */ { 5, 0, 1, -1, 5, 0, 6, 0, 7, 0, 8, },
  /* 160 */ { 1, 0, 1, },
  /* 161 */ { 1, 0, 1, },
  /* 162 */ { 1, 0, 1, },
  /* 163 */ { 1, 0, 1, },
  /* 164 */ { 2, 0, 1, 5, 7, },
  /* 165 */ { 3, 0, 1, 5, 7, 0, 8, },
  /* 166 */ { 2, 0, 1, -5, 7, },
  /* 167 */ { 3, 0, 1, -5, 7, 0, 8, },
  /* 168 */ { 1, 0, 1, },
  /* 169 */ { 1, 0, 1, },
  /* 170 */ { 1, 0, 1, },
  /* 171 */ { 1, 0, 1, },
  /* 172 */ { 2, 0, 1, 6, 7, },
  /* 173 */ { 3, 0, 1, 6, 7, 0, 8, },
  /* 174 */ { 2, 0, 1, -6, 7, },
  /* 175 */ { 3, 0, 1, -6, 7, 0, 8, },
  /* 176 */ { 2, 0, 1, 2, 5, },
  /* 177 */ { 2, 0, 1, 2, 5, },
  /* 178 */ { 2, 0, 1, 2, 5, },
  /* 179 */ { 2, 0, 1, 2, 5, },
  /* 180 */ { 3, 0, 1, 2, 5, 0, 6, },
  /* 181 */ { 3, 0, 1, 2, 5, 0, 6, },
  /* 182 */ { 4, 0, 1, 2, 5, 0, 6, 0, 7, },
  /* 183 */ { 5, 0, 1, 2, 5, 0, 6, 0, 7, 0, 8, },
  /* 184 */ { 2, 0, 1, -2, 5, },
  /* 185 */ { 2, 0, 1, -2, 5, },
  /* 186 */ { 2, 0, 1, -2, 5, },
  /* 187 */ { 2, 0, 1, -2, 5, },
  /* 188 */ { 3, 0, 1, -2, 5, 0, 6, },
  /* 189 */ { 3, 0, 1, -2, 5, 0, 6, },
  /* 190 */ { 4, 0, 1, -2, 5, 0, 6, 0, 7, },
  /* 191 */ { 5, 0, 1, -2, 5, 0, 6, 0, 7, 0, 8, },
  /* 192 */ { 2, 0, 1, 0, 2, },
  /* 193 */ { 2, 0, 1, 0, 2, },
  /* 194 */ { 3, 0, 1, 0, 2, 3, 8, },
  /* 195 */ { 3, 0, 1, 0, 2, -3, 8, },
  /* 196 */ { 2, 0, 1, 0, 2, },
  /* 197 */ { 2, 0, 1, 0, 2, },
  /* 198 */ { 3, 0, 1, 0, 2, 4, 8, },
  /* 199 */ { 3, 0, 1, 0, 2, -4, 8, },
  /* 200 */ { 3, 0, 1, 0, 2, 1, 6, },
  /* 201 */ { 3, 0, 1, 0, 2, 1, 6, },
  /* 202 */ { 4, 0, 1, 0, 2, 1, 6, 0, 7, },
  /* 203 */ { 5, 0, 1, 0, 2, 1, 6, 0, 7, 0, 8, },
  /* 204 */ { 3, 0, 1, 0, 2, -1, 6, },
  /* 205 */ { 3, 0, 1, 0, 2, -1, 6, },
  /* 206 */ { 4, 0, 1, 0, 2, -1, 6, 0, 7, },
  /* 207 */ { 5, 0, 1, 0, 2, -1, 6, 0, 7, 0, 8, },
  /* 208 */ { 2, 0, 1, 0, 2, },
  /* 209 */ { 2, 0, 1, 0, 2, },
  /* 210 */ { 3, 0, 1, 0, 2, 5, 8, },
  /* 211 */ { 3, 0, 1, 0, 2, -5, 8, },
  /* 212 */ { 2, 0, 1, 0, 2, },
  /* 213 */ { 2, 0, 1, 0, 2, },
  /* 214 */ { 3, 0, 1, 0, 2, 6, 8, },
  /* 215 */ { 3, 0, 1, 0, 2, -6, 8, },
  /* 216 */ { 3, 0, 1, 0, 2, 2, 6, },
  /* 217 */ { 3, 0, 1, 0, 2, 2, 6, },
  /* 218 */ { 4, 0, 1, 0, 2, 2, 6, 0, 7, },
  /* 219 */ { 5, 0, 1, 0, 2, 2, 6, 0, 7, 0, 8, },
  /* 220 */ { 3, 0, 1, 0, 2, -2, 6, },
  /* 221 */ { 3, 0, 1, 0, 2, -2, 6, },
  /* 222 */ { 4, 0, 1, 0, 2, -2, 6, 0, 7, },
  /* 223 */ { 5, 0, 1, 0, 2, -2, 6, 0, 7, 0, 8, },
  /* 224 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 225 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 226 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 227 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 228 */ { 4, 0, 1, 0, 2, 0, 3, 1, 7, },
  /* 229 */ { 5, 0, 1, 0, 2, 0, 3, 1, 7, 0, 8, },
  /* 230 */ { 4, 0, 1, 0, 2, 0, 3, -1, 7, },
  /* 231 */ { 5, 0, 1, 0, 2, 0, 3, -1, 7, 0, 8, },
  /* 232 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 233 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 234 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 235 */ { 3, 0, 1, 0, 2, 0, 3, },
  /* 236 */ { 4, 0, 1, 0, 2, 0, 3, 2, 7, },
  /* 237 */ { 5, 0, 1, 0, 2, 0, 3, 2, 7, 0, 8, },
  /* 238 */ { 4, 0, 1, 0, 2, 0, 3, -2, 7, },
  /* 239 */ { 5, 0, 1, 0, 2, 0, 3, -2, 7, 0, 8, },
  /* 240 */ { 4, 0, 1, 0, 2, 0, 3, 0, 4, },
  /* 241 */ { 4, 0, 1, 0, 2, 0, 3, 0, 4, },
  /* 242 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, 1, 8, },
  /* 243 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, -1, 8, },
  /* 244 */ { 4, 0, 1, 0, 2, 0, 3, 0, 4, },
  /* 245 */ { 4, 0, 1, 0, 2, 0, 3, 0, 4, },
  /* 246 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, 2, 8, },
  /* 247 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, -2, 8, },
  /* 248 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, },
  /* 249 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, },
  /* 250 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, },
  /* 251 */ { 5, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, },
  /* 252 */ { 6, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, },
  /* 253 */ { 6, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, },
  /* 254 */ { 7, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, },
  /* 255 */ { 8, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, },
};
