#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef pair <long long, long long> ipair;
const long long N = 100123;

// СНМ
long long dsuP[N], dsuR[N];
// В этот массив записываются все изменения СНМ, чтобы их можно откатить
// При изменении какого-то значения в СНМ в hist записывается пара < указатель, старое значение >
vector <pair<long long*, long long>> hist;

// Для элемента из СНМ возвращает корень дерева, в котором он находится
int dsuRoot(long long v){
    while (dsuP[v] != -1)
        v = dsuP[v];
    return v;
}

// Объединяет два множества. Используется ранговая эвристика.
// При любом изменении содержимого массивов dsuP и dsuR
// в hist записывается адрес и старое значение
void dsuMerge(long long a, long long b){
    a = dsuRoot(a);
    b = dsuRoot(b);
    if (a == b) return;

    if (dsuR[a] > dsuR[b]){
        hist.emplace_back(&dsuP[b], dsuP[b]);
        dsuP[b] = a;
    }
    else if (dsuR[a] < dsuR[b]){
        hist.emplace_back(&dsuP[a], dsuP[a]);
        dsuP[a] = b;
    }
    else{
        hist.emplace_back(&dsuP[a], dsuP[a]);
        hist.emplace_back(&dsuR[b], dsuR[b]);
        dsuP[a] = b;
        ++dsuR[b];
    }
}

struct Query{
    long long u, v;
    char t;
};
Query q[N];

// Дерево отрезков, в каждой вершине которого хранится список рёбер
vector < ipair > t[N*7];

// Эта функция добавляет ребро на отрезок
// [l r] - отрезок, на который добавляется ребро
// uv - ребро, c - текущая вершина дерева отрезков,
// [cl cr] - отрезок текущей вершины дерева отрезков
void addEdge(long long l, long long r, ipair uv, long long c, long long cl, long long cr)
{
    if (l > cr || r < cl)
        return;
    if (l <= cl && cr <= r)
    {
        t[c].push_back(uv);
        return;
    }
    long long mid = (cl + cr) / 2;
    addEdge(l, r, uv, c*2+1, cl, mid);
    addEdge(l, r, uv, c*2+2, mid+1, cr);
}

// Обход дерева отрезков в глубину
void go(long long c, long long cl, long long cr){
    long long startSize = hist.size();
    // Добавляем рёбра при входе в вершину
    for (ipair uv : t[c])
        dsuMerge(uv.first, uv.second);

    if (cl == cr) {
        // Если эта вершина - лист, то отвечаем на запрос
        if (q[cl].t == '?') {
            if (dsuRoot(q[cl].u) == dsuRoot(q[cl].v)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    else {
        long long mid = (cl + cr) / 2;
        go(c*2+1, cl, mid);
        go(c*2+2, mid+1, cr);
    }

    // Откатываем изменения СНМ
    while ((long long)hist.size() > startSize)
    {
        *hist.back().first = hist.back().second;
        hist.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    // Формат входных данных:
    // n и m, затем в m строках запросы: по три числа t, u, v
    // t - тип (1 - добавить ребро, 2 - удалить, 3 - принадлежат ли одной компоненте)
    // Нумерация вершин с нуля
    long long n, m, p;
    cin >> n >> m >> p;
    for (long long i = 0; i <= n; ++i) // Инициализация СНМ
        dsuP[i] = -1;

    // В этом массиве для каждого ещё не удалённого ребра хранится
    // на каком запросе оно было создано
    set <pair<ipair, long long>> edges;
    for (long long i = 0; i < m; ++i) {
        cin >> q[i].u >> q[i].v;
        if (q[i].u > q[i].v) swap(q[i].u, q[i].v);
        q[i].t = '+';
        edges.emplace(ipair(q[i].u, q[i].v), i);
    }
    for (long long i = m; i < m+p; ++i) {
        cin >> q[i].t >> q[i].u >> q[i].v;
        // Поскольку рёбра неориентированные, u v должно означать то же самое, что и v u
        if (q[i].u > q[i].v) swap(q[i].u, q[i].v);
            // При удалении ребра берём из set время его добавления - так мы узнаём отрезок заросов,
            // на котором оно существует. Если есть несколько одинаковых рёбер, можно брать любое.
        if (q[i].t == '-')
        {
            auto iter = edges.lower_bound(make_pair(ipair(q[i].u, q[i].v), 0));
            addEdge(iter->second, i, iter->first, 0, 0, m + p - 1);
            edges.erase(iter);
        }
    }
    // Обрабатываем рёбра, которые не были удалены
    for (auto e : edges)
        addEdge(e.second, m + p - 1, e.first, 0, 0, m + p - 1);

    // Запускаем dfs по дереву отрезков
    go(0, 0, m + p - 1);
    // Выводим ответ.
    // При обходе дерева отрезков запросы обрабатываются в том же порядке, в котором они даны,
    // поэтому ответ можно выводить прямо в go без заполнения answer

    return 0;
}