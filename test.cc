#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// 配置参数
#define N 1024*10
#define TOLERANCE 1e-6  // 收敛容差
#define MAX_ITERATIONS 1000  // 最大迭代次数
#define NUM_THREADS 24  // 线程数

// 分配2D数组
float** allocate_grid(int n) {
    float** grid = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        grid[i] = (float*)malloc(n * sizeof(float));
    }
    return grid;
}

// 初始化网格
void initialize_grid(float** grid, int n) {
    // 设置边界条件
    for (int i = 0; i < n; i++) {
        grid[i][0] = 1.0f;     // 左边界
        grid[i][n-1] = 0.0f;   // 右边界
        grid[0][i] = 1.0f;     // 上边界
        grid[n-1][i] = 0.0f;   // 下边界
    }

    // 初始化内部点
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            grid[i][j] = 0.5f;
        }
    }
}

// 求解器主函数
void solve(float** grid, int n) {
    bool done = false;
    float diff;
    int iterations = 0;

    omp_set_num_threads(NUM_THREADS);

    while (!done && iterations < MAX_ITERATIONS) {
        diff = 0.0f;

        #pragma omp parallel reduction(+:diff)
        {
            int tid = omp_get_thread_num();
            int chunk_size = (n-2) / NUM_THREADS;
            int start = 1 + tid * chunk_size;
            int end = (tid == NUM_THREADS-1) ? n-1 : start + chunk_size;

            float local_diff = 0.0f;

            // 计算新值
            for (int i = start; i < end; i++) {
                for (int j = 1; j < n-1; j++) {
                    float old_val = grid[i][j];
                    grid[i][j] = 0.2f * (
                        grid[i-1][j] + grid[i+1][j] +
                        grid[i][j-1] + grid[i][j+1] +
                        old_val
                    );
                    local_diff += fabs(grid[i][j] - old_val);
                }
            }

            diff += local_diff;
        }

        // 检查收敛
        if (diff/(n*n) < TOLERANCE) {
            done = true;
        }

        iterations++;

        if (iterations % 100 == 0) {
            printf("Iteration %d, diff = %f\n", iterations, diff/(n*n));
        }
    }

    printf("Solved in %d iterations\n", iterations);
}

// 打印网格（用于调试小网格）
void print_grid(float** grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.4f ", grid[i][j]);
        }
        printf("\n");
    }
}

// 释放内存
void free_grid(float** grid, int n) {
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    // 分配并初始化网格
    float** grid = allocate_grid(N);
    initialize_grid(grid, N);

    // 计时开始
    double start_time = omp_get_wtime();

    // 求解
    solve(grid, N);

    // 计时结束
    double end_time = omp_get_wtime();
    printf("Time taken: %f seconds\n", end_time - start_time);

    // 如果网格较小，打印结果
    if (N <= 10) {
        printf("\nFinal grid:\n");
        print_grid(grid, N);
    }

    // 清理内存
    free_grid(grid, N);

    return 0;
}
