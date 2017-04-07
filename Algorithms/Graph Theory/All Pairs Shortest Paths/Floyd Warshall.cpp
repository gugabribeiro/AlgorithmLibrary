typedef vector<vector<int>> Matrix;

struct FloydWarshall {

  static Matrix apsp(const Matrix& matrix) {
    Matrix res = matrix;
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
        }
      }
    }
    return res;
  }
};