#include "util.h"
#include <algorithm>

#ifndef TKey
    #define TKey              1
#endif
#ifndef TVal
    #define TVal              1
#endif
#if __GNUC__ > 4 && __linux__
#include <ext/pb_ds/assoc_container.hpp>
#endif

#ifndef ET
//#define ET                 1
#endif

#if SMAP
#include "flat_map.hpp"
#endif


static void printInfo(char* out);
std::map<std::string, std::string> maps =
{
//    {"stl_hash", "unordered_map"},
//    {"stl_map", "stl_map"},
//    {"fmap", "flat_map"},
//    {"btree", "btree_map"},


//    {"emhash2", "emhash2"},
//    {"emhash3", "emhash3"},
//    {"emhash4", "emhash4"},

    {"emhash5", "emhash5"},
    {"emhash6", "emhash6"},
    {"emhash7", "emhash7"},
    {"emhash8", "emhash8"},

//    {"jg_dense", "jg_dense"},
//    {"rigtorp", "rigtorp"},
//    {"qchash", "qc-hash"},
//    {"fph", "fph-table"},


//    {"lru_time", "lru_time"},
//    {"lru_size", "lru_size"},

    {"emilib2", "emilib2"},
    {"emilib1", "emilib1"},
    {"emilib3", "emilib3"},
//    {"simd_hash", "simd_hash"},
//    {"emilib4", "emilib4"},
//    {"emilib3", "emilib3"},
//    {"ktprime", "ktprime"},
    {"abslf", "absl_flat"},
//    {"f14_value", "f14_value"},

    {"martind", "martin_dense"},
#if ET
    {"f14_vector", "f14_vector"},
    {"fht", "fht"},
    {"cuckoo", "cuckoo hash"},
    {"zhashmap", "zhashmap"},
    {"martinf", "martin_flat"},
    {"phmap", "phmap_flat"},
//    {"hrdset", "hrdset"},

    {"tslr", "tsl_robin"},
    {"skaf", "ska_flat"},

    {"hopsco", "tsl_hopsco"},
    {"sbyte", "ska_byte"},
#endif
};


//rand data type
#ifndef RT
    #define RT 1  //1 wyrand 2 Sfc4 3 RomuDuoJr 4 Lehmer64 5 mt19937_64
#endif

//#define CUCKOO_HASHMAP       1
//#define EM3               1
//#define PHMAP_HASH        1
//#define WY_HASH           1

//#define FL1                 1

//feature of emhash
//#define EMH_FIBONACCI_HASH  1
//#define EMH_BUCKET_INDEX    2
//#define EMH_REHASH_LOG      1234567

//#define EMH_STATIS          1
//#define EMH_SAFE_HASH       1
//#define EMH_IDENTITY_HASH   1

//#define EMH_LRU_SET         1
//#define EMH_ERASE_SMALL     1
//#define EMH_HIGH_LOAD         2345
//#define EMH_FIND_HIT        1

#ifdef EM3
#include "emhash/hash_table2.hpp"
#include "emhash/hash_table3.hpp"
#include "emhash/hash_table4.hpp"
#include "emhash/hash_table557.hpp"
#endif

#include "../hash_table5.hpp"
#include "../hash_table6.hpp"
#include "../hash_table7.hpp"
#include "../hash_table8.hpp"

//https://jishuin.proginn.com/p/763bfbd338d0
//https://en.wikipedia.org/wiki/Hash_table
//https://zhuanlan.zhihu.com/p/363213858
//https://www.zhihu.com/question/46156495
//http://www.brendangregg.com/index.html

//https://eourcs.github.io/LockFreeCuckooHash2
//https://lemire.me/blog/2018/08/15/fast-strongly-universal-64-bit-hashing-everywhere/
////some others
//https://sites.google.com/view/patchmap/overview
//https://github.com/ilyapopov/car-race
//https://hpjansson.org/blag/2018/07/24/a-hash-table-re-hash/
//https://www.reddit.com/r/cpp/comments/auwbmg/hashmap_benchmarks_what_should_i_add/
//https://www.youtube.com/watch?v=M2fKMP47slQ
//https://yq.aliyun.com/articles/563053

//https://engineering.fb.com/developer-tools/f14/
//https://github.com/facebook/folly/blob/master/folly/container/F14.md

//https://martin.ankerl.com/2019/04/01/hashmap-benchmarks-01-overview/
//https://martin.ankerl.com/2016/09/21/very-fast-hashmap-in-c-part-3/

//https://attractivechaos.wordpress.com/2018/01/13/revisiting-hash-table-performance/
//https://attractivechaos.wordpress.com/2019/12/28/deletion-from-hash-tables-without-tombstones/#comment-9548
//https://tessil.github.io/2016/08/29/benchmark-hopscotch-map.html
//https://probablydance.com/2017/02/26/i-wrote-the-fastest-hashtable/
//https://andre.arko.net/2017/08/24/robin-hood-hashing/
//http://www.ilikebigbits.com/2016_08_28_hash_table.html
//http://www.idryman.org/blog/2017/05/03/writing-a-damn-fast-hash-table-with-tiny-memory-footprints/
//https://jasonlue.github.io/algo/2019/08/27/clustered-hashing-basic-operations.html
//https://bigdata.uni-saarland.de/publications/p249-richter.pdf
//https://gankra.github.io/blah/hashbrown-tldr/ swiss
//https://leventov.medium.com/hash-table-tradeoffs-cpu-memory-and-variability-22dc944e6b9a
//https://jguegant.github.io/blogs/tech/dense-hash-map.html

//
#if FHT_HMAP && __linux__
#include <sys/mman.h>
#include "fht/fht_ht.hpp" // https://github.com/goldsteinn/hashtable_test/blob/master/my_table/fht_ht.hpp
#endif

#if FOLLY
#include "folly/container/F14Map.h"
#endif

#if CUCKOO_HASHMAP
#include "libcuckoo/cuckoohash_map.hh"
#endif

#if CXX20
#include "martinus/unordered_dense.h"
#endif

#if HOOD_HASH
    #include "martinus/robin_hood.h"    //https://github.com/martin/robin-hood-hashing/blob/master/src/include/robin_hood.h
#endif
#if PHMAP_HASH
    #include "phmap/phmap.h"          //https://github.com/greg7mdp/parallel-hashmap/tree/master/parallel_hashmap
#endif

//#include "qchash/qc-hash.hpp" //https://github.com/daskie/qc-hash
//#include "fph/dynamic_fph_table.h" //https://github.com/renzibei/fph-table

#if X86
#include "emilib/emilib2s.hpp"
#include "emilib/emilib2.hpp"
#include "emilib/emilib.hpp"
#endif
//#include "emilib/emilib21.hpp"

#if ET
//    #include "emilib/emilib32.hpp"
//    #include "zhashmap/hashmap.h"

#if X86_64

#if __cplusplus > 201402L || _MSVC_LANG >= 201402L
    #include "hrd/hash_set7.h"        //https://github.com/hordi/hash/blob/master/include/hash_set7.h
#endif
    #include "emilib/emilib33.hpp"
    #include "ska/flat_hash_map.hpp"  //https://github.com/skarupke/flat_hash_map/blob/master/flat_hash_map.hpp
//    #include "simd_hash_map/simd_hash_map.hpp"
#endif

    #include "tsl/robin_map.h"        //https://github.com/tessil/robin-map

    #include "lru_size.h"
    #include "lru_time.h"
    #include "phmap/btree.h"          //https://github.com/greg7mdp/parallel-hashmap/tree/master/parallel_hashmap
#if ET > 1
    #include "tsl/hopscotch_map.h"    //https://github.com/tessil/hopscotch-map
    #include "ska/bytell_hash_map.hpp"//https://github.com/skarupke/flat_hash_map/blob/master/bytell_hash_map.hpp
#endif
    #include "phmap/phmap.h"          //https://github.com/greg7mdp/parallel-hashmap/tree/master/parallel_hashmap
    #include "martinus/robin_hood.h"    //https://github.com/martin/robin-hood-hashing/blob/master/src/include/robin_hood.h
#endif


#ifndef PACK
#define PACK 128
#endif
struct StructValue
{
    StructValue(int64_t i = 0)
    {
        lScore = i;
        lUid = 0;
        iRank = iUpdateTime = 0;
    }

    bool operator == (const StructValue& v) const
    {
        return v.lScore == lScore;
    }

    int64_t operator ()() const
    {
        return lScore;
    }

    bool operator < (const StructValue& r) const
    {
        return lScore < r.lScore;
    }

    int64_t operator + (int64_t r) const { return lScore + r; }

    int64_t lUid;
    int64_t lScore;
    int  iUpdateTime;
    int  iRank;

#if PACK >= 24
    char data[(PACK - 24) / 8 * 8];
#endif

#if VCOMP
    std::string sdata = {"test data input"};
    std::vector<int> vint = {1,2,3,4,5,6,7,8};
    std::map<std::string, int> msi = {{"111", 1}, {"1222", 2}};
#endif
};

struct StuHasher
{
    std::size_t operator()(const StructValue& v) const
    {
        return v.lScore * 11400714819323198485ull;
    }
};

#if TKey == 0
#ifndef SMK
    typedef unsigned int keyType;
    #define sKeyType    "int"
#else
    typedef short        keyType;
    #define sKeyType    "short"
#endif
    #define TO_KEY(i)   (keyType)i
    #define KEY_INT     1
#elif TKey == 1
    typedef int64_t      keyType;
    #define TO_KEY(i)   (keyType)i
    #define sKeyType    "int64_t"
    #define KEY_INT     1
#elif TKey == 2
    #define KEY_STR     1
    typedef std::string keyType;
    #define TO_KEY(i)   std::to_string(i)
    #define sKeyType    "string"
#elif TKey == 3
    #define KEY_CLA    1
    typedef StructValue keyType;
    #define TO_KEY(i)   StructValue((int64_t)i)
    #define sKeyType    "Struct"
#elif TKey == 4
    #define KEY_STR     1
    typedef std::string_view keyType;
    #define TO_KEY(i)   std::to_string(i)
    #define sKeyType    "string_view"
#endif

#if TVal == 0
    typedef int         valueType;
    #define TO_VAL(i)   i
    #define TO_SUM(i)   i
    #define sValueType  "int"
#elif TVal == 1
    typedef int64_t     valueType;
    #define TO_VAL(i)   i
    #define TO_SUM(i)   i
    #define sValueType  "int64_t"
#elif TVal == 2
    typedef std::string valueType;
    #define TO_VAL(i)   ""
    #define TO_SUM(i)   i.size()
    #define sValueType  "string"
#elif TValue == 3
    typedef std::string_view valueType;
    #define TO_VAL(i)   #i
    #define TO_SUM(i)   i.size()
    #define sValueType  "string_view"
#else
    typedef StructValue valueType;
    #define TO_VAL(i)   i
    #define TO_SUM(i)   i.lScore
    #define sValueType  "Struct"
#endif

static int test_case = 0;
static int loop_vector_time = 0;
static int func_index = 0, func_size = 10;
static int func_first = 0, func_last = 0;
static float hlf = 0.0;

static std::map<std::string, int64_t> func_result;
//func:hash -> time
static std::map<std::string, std::map<std::string, int64_t>> once_func_hash_time;

static void check_func_result(const std::string& hash_name, const std::string& func, size_t sum, int64_t ts1, int weigh = 1)
{
    if (func_result.find(func) == func_result.end()) {
        func_result[func] = sum;
    } else if ((int64_t)sum != func_result[func]) {
        printf("%s %s %zd != %zd (o)\n", hash_name.data(), func.data(), (size_t)sum, (size_t)func_result[func]);
    }

    auto& showname = maps[hash_name];
    once_func_hash_time[func][showname] += (getus() - ts1) / weigh;
    func_index ++;

    long ts = (getus() - ts1) / 1000;

    if (func_first < func_last)  {
        if (func_index == func_first)
            printf("%8s  (%.3f): ", hash_name.data(), hlf);
        if (func_index >= func_first && func_index <= func_last)
            printf("%8s %4ld, ", func.data(), ts);
        if (func_index == func_last)
            printf("\n");
    } else {
        if (func_index == 1)
            printf("%8s  (%.3f): ", hash_name.data(), hlf);
        if (func_index >= func_first || func_index <= func_last)
            printf("%8s %4ld, ", func.data(), ts);
        if (func_index == func_size)
            printf("\n");
    }
}

static void inline hash_convert(const std::map<std::string, int64_t>& hash_score, std::multimap <int64_t, std::string>& score_hash)
{
    for (const auto& v : hash_score)
        score_hash.emplace(v.second, v.first);
}

static void add_hash_func_time(std::map<std::string, std::map<std::string, int64_t>>& func_hash_score, std::multimap <int64_t, std::string>& once_score_hash)
{
    std::map<std::string, int64_t> once_hash_score;
    for (auto& v : once_func_hash_time) {
        int64_t maxv = v.second.begin()->second;
        for (auto& h : v.second) {
            if (h.second > maxv)
                maxv = h.second;
        }

        for (auto& f : v.second) {
            const auto score = (100ull * f.second) / maxv; //f.second;
            func_hash_score[v.first][f.first] += score;
            once_hash_score[f.first]          += score;
        }
    }
    hash_convert(once_hash_score, once_score_hash);

    const auto last  = double(once_score_hash.rbegin()->first);
    const auto first = double(once_score_hash.begin()->first);
    //print once score
    for (auto& v : once_score_hash) {
        printf("%5d   %13s   (%4.2lf %6.1lf%%)\n", int(v.first / (func_index - 1)), v.second.data(), last * 1.0 / v.first, first * 100.0 / v.first);
    }
}

static void dump_func(const std::string& func, const std::map<std::string, int64_t >& hash_rtime, std::map<std::string, int64_t>& hash_score, std::map<std::string, std::map<std::string, int64_t>>& hash_func_score)
{
    std::multimap <int64_t, std::string> rscore_hash;
    hash_convert(hash_rtime, rscore_hash);

    puts(func.data());

    auto mins = rscore_hash.begin()->first;
    for (auto& v : rscore_hash) {
        hash_score[v.second] += (int)((mins * 100) / (v.first + 1e-3));

        //hash_func_score[v.second][func] = (int)((mins * 100) / (v.first + 1));
        hash_func_score[v.second][func] = v.first / test_case;
        printf("%4d        %-20s   %-2.1f%%\n", (int)(v.first / test_case), v.second.data(), ((mins * 100.0f) / v.first));
    }
    putchar('\n');
}

static void dump_all(std::map<std::string, std::map<std::string, int64_t>>& func_rtime, std::multimap<int64_t, std::string>& score_hash)
{
    std::map<std::string, int64_t> hash_score;
    std::map<std::string, std::map<std::string, int64_t>> hash_func_score;
    for (const auto& v : func_rtime) {
        dump_func(v.first, v.second, hash_score, hash_func_score);
    }
    hash_convert(hash_score, score_hash);

    if (test_case % 100 != 0)
        return;

    std::string pys =
    "import numpy as np\n"
    "import matplotlib.pyplot as plt\n\n"
    "def autolabel(rects):\n"
        "\tfor rect in rects:\n"
        "\t\twidth = rect.get_width()\n"
        "\t\tplt.text(width + 1.0, rect.get_y(), '%s' % int(width))\n\n"
    "divisions = [";

    pys.reserve(2000);
    for (const auto& v : func_rtime) {
        pys += "\"" + v.first + "\",";
    }

    pys.back() = ']';
    pys += "\n\n";

    auto hash_size = hash_func_score.size();
    auto func_size = func_rtime.size();

    pys += "plt.figure(figsize=(14," + std::to_string(func_size) + "))\n";
    pys += "index = np.arange(" + std::to_string(func_size) + ")\n";
    if (hash_size > 4)
        pys += "width = " + std::to_string(0.8 / hash_size) + "\n\n";
    else
        pys += "width = 0.20\n\n";

    std::string plt;
    int id = 0;
    static std::vector<std::string> colors = {
        "cyan", "magenta",
        "green", "red", "blue", "yellow", "black", "orange", "brown", "grey", "pink",
        "#eeefff", "burlywood",
    };

    for (auto& kv : hash_func_score) {
        pys += kv.first + "= [";
        for (auto& vk : kv.second) {
            pys += std::to_string(vk.second) + ",";
        }
        pys.back() = ']';
        pys += "\n";

        plt += "a" + std::to_string(id + 1) + " = plt.barh(index + width * " + std::to_string(id) + "," + kv.first +
            ",width, label = \"" + kv.first + "\")\n";
        plt += "autolabel(a" + std::to_string(id + 1) + ")\n\n";
        id ++;
    }

    //os
    char os_info[2048]; printInfo(os_info);

    pys += "\n" + plt + "\n";
    auto file = std::string(sKeyType) + "_" + sValueType;
    pys += std::string("file = \"") + file + ".png\"\n\n";
    pys += std::string("plt.title(\"") + file + "-" + std::to_string(test_case) + "\")\n";
    pys +=
        "plt.xlabel(\"performance\")\n"
        "plt.xlabel(\"" + std::string(os_info) + "\")\n"
        "plt.yticks(index + width / 2, divisions)\n"
        "plt.legend()\n"
        "plt.show()\n"
        "plt.savefig(file)\n";

    pys += std::string("\n\n# ") + os_info;

    //puts(pys.data());
    std::ofstream  outfile;
    auto full_file = file + ".py";
    outfile.open("./" + full_file, std::fstream::out | std::fstream::trunc | std::fstream::binary);
    if (outfile.is_open())
        outfile << pys;
    else
        printf("\n\n =============== can not open %s ==============\n\n", full_file.data());

    outfile.close();
}

template<class hash_type>
void hash_iter(const hash_type& ht_hash, const std::string& hash_name)
{
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : ht_hash)
        sum += 1;

    for (auto& v : ht_hash)
        sum += 2;

    for (auto it = ht_hash.begin(); it != ht_hash.end(); ++it)
#if KEY_INT
        sum += it->first;
#elif KEY_CLA
    sum += it->first.lScore;
#else
    sum += it->first.size();
#endif

#ifndef SMAP
    for (auto it = ht_hash.cbegin(); it != ht_hash.cend(); ++it)
#if KEY_INT
        sum += it->first;
#elif KEY_CLA
    sum += it->first.lScore;
#else
    sum += it->first.size();
#endif

    hlf = ht_hash.load_factor();
#endif
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void erase_reinsert(hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList) {
#ifndef SMAP
        ht_hash.emplace(v, TO_VAL(0));
#else
        ht_hash[v] = TO_VAL(0);
#endif
        sum ++;
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void insert_erase(const std::string& hash_name, const std::vector<keyType>& vList)
{
#if TVal < 2
    hash_type ht_hash;
    auto ts1 = getus(); size_t sum = 0;
    const auto vsmall = 1024 + vList.size() % 1024;
    for (size_t i = 0; i < vList.size(); i++) {
        sum += ht_hash.emplace(vList[i], TO_VAL(0)).second;
        if (i > vsmall)
            ht_hash.erase(vList[i - vsmall]);
    }

    if (vList.size() % 3 == 0)
        ht_hash.clear();

    //load_factor = 0.5
    const auto vmedium = (1u << ilog(vList.size() / 100, 2)) * 5 / 10;
    for (size_t i = 0; i < vList.size(); i++) {
        auto it = ht_hash.emplace(vList[i], TO_VAL(0));
        if (i > vmedium)
            ht_hash.erase(it.first);
    }

    if (test_case % 2 == 0)
        ht_hash.clear();

    ht_hash.max_load_factor(0.75);
    //load_factor = 0.8
    const auto vsize = (1u << ilog(vList.size() / 8, 2)) * 75 / 100;
    ht_hash.reserve(vsize / 2);
    for (size_t i = 0; i < vList.size(); i++) {
        ht_hash[vList[i]] = TO_VAL(0);
        if (i > vsize)
            sum += ht_hash.erase(vList[i - vsize]);
    }

    check_func_result(hash_name, __FUNCTION__, sum, ts1);
//    printf(" = %.2f\n", ht_hash.load_factor());
#endif
}

template<class hash_type>
void insert_no_reserve(const std::string& hash_name, const std::vector<keyType>& vList)
{
    hash_type ht_hash;
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList)
        sum += ht_hash.emplace(v, TO_VAL(0)).second;

    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void insert_reserve(hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 0;
#ifndef SMAP
    ht_hash.max_load_factor(0.9f);
    ht_hash.reserve(vList.size());
#endif

    for (const auto& v : vList)
        sum += ht_hash.emplace(v, TO_VAL(0)).second;
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void insert_hit(hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList) {
        sum += ht_hash.emplace(v, TO_VAL(0)).second;
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void multi_small_ife(const std::string& hash_name, const std::vector<keyType>& vList)
{
#if KEY_INT
    size_t sum = 0;
    const auto hash_size = vList.size() / 1003 + 10;
    const auto ts1 = getus();

    if (test_case % 2) {
        auto mh = new hash_type[hash_size];
        for (const auto& v : vList) {
            auto hash_id = ((uint32_t)v) % hash_size;
            sum += mh[hash_id].emplace(v, TO_VAL(0)).second;
        }

        for (const auto& v : vList) {
            auto hash_id = ((uint32_t)v) % hash_size;
            sum += mh[hash_id].count(v);
        }

        for (const auto& v : vList) {
            auto hash_id = ((uint32_t)v) % hash_size;
            sum += mh[hash_id].erase(v + v % 2);
        }

        delete []mh;
    } else {
        hash_type hashm;
        for (const auto v : vList) {
            const keyType v2 = v % hash_size;
            sum += hashm.emplace(v2, TO_VAL(0)).second;
            sum += hashm.erase(v2 + v % 2);
            sum += hashm.count(v2 / 2);
        }
    }

    check_func_result(hash_name, __FUNCTION__, sum, ts1, 2);
#endif
}

template<class hash_type>
void insert_find_erase(const hash_type& ht_hash, const std::string& hash_name, std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 1;
    hash_type tmp(ht_hash);

    for (auto & v : vList) {
#if KEY_INT
        auto v2 = keyType(v % 2 == 0 ? v + sum : v - sum);
#elif KEY_CLA
        int64_t v2(v.lScore + sum);
#elif TKey != 4
        v += char(128 + (int)v[0]);
        auto &v2 = v;
#else
        keyType v2(v.data(), v.size() - 1);
#endif

#ifndef SMAP
        sum += tmp.count(v2);
        auto it = tmp.emplace(std::move(v2), TO_VAL(0)).first;
        tmp.erase(it);
#else
        tmp[v2] = TO_VAL(0);
        auto it = tmp.find(v2);
        tmp.erase(v2);
#endif
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1, 3);
}

template<class hash_type>
void insert_cache_size(const std::string& hash_name, const std::vector<keyType>& vList, const char* level, const uint32_t cache_size, const uint32_t min_size)
{
    const auto lsize = cache_size + vList.size() % min_size;
    hash_type tmp, empty;

    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList)
    {
        sum += tmp.emplace(v, TO_VAL(0)).second;
        //sum += tmp.count(v);
        if (tmp.size() > lsize) {
            if (lsize % 2 == 0)
                tmp.clear();
            else {
                tmp = std::move(empty);
            }
        }
    }
    check_func_result(hash_name, level, sum, ts1);
}

template<class hash_type>
void insert_high_load(const std::string& hash_name, const std::vector<keyType>& vList)
{
    size_t sum = 0;
    size_t pow2 = 2u << ilog(vList.size(), 2);
    hash_type tmp;

    const auto max_loadf = 1 - 0.001f;
#ifndef SMAP
    tmp.max_load_factor(max_loadf);
    tmp.reserve(pow2 / 2);
#endif
    int minn = (max_loadf - 0.2f) * pow2, maxn = int(max_loadf * pow2);
    int i = 0;

    //fill data to min factor
    for (; i < minn; i++) {
        if (i < (int)vList.size())
            tmp.emplace(vList[i], TO_VAL(0));
        else {
            auto& v = vList[i - vList.size()];
#if KEY_INT
            auto v2 = v - i;
#elif KEY_CLA
            auto v2 = v.lScore + (v.lScore / 11) + i;
#elif TKey != 4
            auto v2 = v; v2[0] += '2';
#else
            keyType v2(v.data(), v.size() - 1);
#endif
            tmp.emplace(std::move(v2), TO_VAL(0));
        }
    }

    auto ts1 = getus();
    for (; i  < maxn; i++) {
        auto& v = vList[i - minn];
#if KEY_INT
        auto v2 = v + i;
#elif KEY_CLA
        auto v2 = (v.lScore / 7) + 4 * v.lScore;
#elif TKey != 4
        auto v2 = v; v2[0] += '1';
#else
        keyType v2(v.data(), v.size() - 1);
#endif
        //tmp[v2] = TO_VAL(0);
        sum += tmp.count(v2);
        tmp.emplace(std::move(v2), TO_VAL(0));
    }

    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

#if FL1
static uint8_t l1_cache[64 * 1024];
#endif
template<class hash_type>
void find_hit_0(const hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    size_t sum = 0;

#if KEY_STR
#if TKey != 4
    auto skey = get_random_alphanum_string(STR_SIZE);
#endif
#endif

    auto ts1 = getus();
    for (const auto& v : vList) {
#if KEY_STR
#if TKey != 4
        skey[v.size() % STR_SIZE + 1] ++;
        sum += ht_hash.count(skey);
#else
        std::string_view skey = "notfind_view";
        sum += ht_hash.count(skey);
#endif
#else
        keyType v2(v + 1);
        sum += ht_hash.find(v2) != ht_hash.end();
#endif
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void find_hit_50(const hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList) {
#if FL1
        if (sum % (1024 * 256) == 0)
            memset(l1_cache, 0, sizeof(l1_cache));
#endif
        sum += ht_hash.count(v);
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void find_hit_50_erase(const hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto tmp = ht_hash;
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList) {
        auto it = tmp.find(v);
        if (it == tmp.end())
            sum ++;
        else
            tmp.erase(it);
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void find_hit_100(const hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList) {
#if KEY_INT
        sum += ht_hash.count(v);
#elif KEY_CLA
        sum += ht_hash.count(v);
#else
        sum += ht_hash.count(v);
#endif
#if FL1
        if (sum % (1024 * 64) == 0)
            memset(l1_cache, 0, sizeof(l1_cache));
#endif
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void find_erase_50(const hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList) {
#ifndef SMAP
        sum += ht_hash.count(v);
#endif
        sum += ht_hash.find(v) != ht_hash.end();
    }
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void erase_50(hash_type& ht_hash, const std::string& hash_name, const std::vector<keyType>& vList)
{
    auto ts1 = getus(); size_t sum = 0;
    for (const auto& v : vList)
        sum += ht_hash.erase(v);

#if QC_HASH == 0
    auto tmp = ht_hash; auto id = 1;
    for (auto it = tmp.begin(); it != tmp.end(); ) {
#if KEY_INT
        if (it->first % 2 == 0)
#else
        if (id++ % 2 == 0)
#endif
            it = tmp.erase(it);
        else
            ++it;
    }
#if KEY_INT
    sum += tmp.size();
#endif
#endif
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

template<class hash_type>
void hash_clear(hash_type& ht_hash, const std::string& hash_name)
{
    if (ht_hash.size() > 1000000) {
        auto ts1 = getus();
        size_t sum = ht_hash.size();
        ht_hash.clear(); ht_hash.clear();
        check_func_result(hash_name, __FUNCTION__, sum, ts1);
    }
}

template<class hash_type>
void copy_clear(hash_type& ht_hash, const std::string& hash_name)
{
    size_t sum = 0;
    auto ts1 = getus();
    hash_type thash = ht_hash;
    sum += thash.size();

    ht_hash = thash;
    sum  += ht_hash.size();

    ht_hash = std::move(ht_hash);
    ht_hash = std::move(thash);
    sum  += ht_hash.size();
    assert(ht_hash.size() > 0 && thash.size() == 0);

    ht_hash.clear(); thash.clear();
    ht_hash.clear(); thash.clear();
    sum  += ht_hash.size();

    assert(ht_hash.size() == thash.size());
    check_func_result(hash_name, __FUNCTION__, sum, ts1);
}

#if PACK >= 24 && VCOMP == 0
static_assert(sizeof(StructValue) == PACK, "PACK >=24");
#endif

//https://en.wikipedia.org/wiki/Gamma_distribution#/media/File:Gamma_distribution_pdf.svg
//https://blog.csdn.net/luotuo44/article/details/33690179
static int buildTestData(int size, std::vector<keyType>& randdata)
{
    randdata.reserve(size);

#if RT == 2
    Sfc4 srng(size);
#elif WYHASH_LITTLE_ENDIAN && RT == 1
    WyRand srng(size);
#elif RT == 3
    RomuDuoJr srng(size);
#elif (RT == 4 && __SIZEOF_INT128__)
    Lehmer64 srng(size);
#else
    std::mt19937_64 srng(size);
#endif

#ifdef KEY_STR
    for (int i = 0; i < size; i++)
#if TKey != 4
        randdata.emplace_back(get_random_alphanum_string(srng() % STR_SIZE + 4));
#else
        randdata.emplace_back(get_random_alphanum_string_view(srng() % STR_SIZE + 4));
#endif

    return 0;
#else

#if RA > 0
    const auto iRation = RA;
#else
    const auto iRation = 1;
#endif

    auto flag = 0;
    if (srng() % 100 >= iRation)
    {
        for (int i = 0; i < size ; i++) {
            auto key = TO_KEY(srng());
            randdata.emplace_back(key);
        }
    }
    else
    {
        flag = srng() % 5 + 1;
        const auto pow2 = 2u << ilog(size, 2);
        auto k = srng();
        for (int i = 1; i <= size; i ++) {
            k ++;
            if (flag == 2)
                k += (1 << 8) - 1;
            else if (flag == 3) {
                k += pow2 + 32 - srng() % 64;
                if (srng() % 64 == 0)
                    k += 80;
            }
            else if (flag == 4) {
                if (srng() % 32 == 0)
                    k += 32;
            } else if (flag == 5) {
                k = i * (uint64_t)pow2 + srng() % (pow2 / 8);
            }

            randdata.emplace_back(k);
        }
    }

    return flag;
#endif
}

template<class hash_type>
void benOneHash(const std::string& hash_name, const std::vector<keyType>& oList)
{
    if (maps.find(hash_name) == maps.end())
        return;

    if (test_case == 0)
        printf("%s:size %zd\n", hash_name.data(), sizeof(hash_type));

    {
        hash_type hash;
        const uint32_t l1_size = (32 * 1024)   / (sizeof(keyType) + sizeof(valueType));
        //const uint32_t l2_size = (256 * 1024)   / (sizeof(keyType) + sizeof(valueType));
        const uint32_t l3_size = (8 * 1024 * 1024) / (sizeof(keyType) + sizeof(valueType));

        func_index = 0;
#if 1
        multi_small_ife <hash_type>(hash_name, oList);

#if QC_HASH == 0 || QC_HASH == 2
        insert_erase     <hash_type>(hash_name, oList);
#endif
        insert_high_load <hash_type>(hash_name, oList);

        insert_cache_size <hash_type>(hash_name, oList, "insert_l1_cache", l1_size, l1_size + 1000);
//        insert_cache_size <hash_type>(hash_name, oList, "insert_l2_cache", l2_size, l2_size + 1000);
        insert_cache_size <hash_type>(hash_name, oList, "insert_l3_cache", l3_size, l3_size + 1000);

        insert_no_reserve <hash_type>(hash_name, oList);

        insert_hit<hash_type>(hash,hash_name, oList);
        find_hit_100<hash_type>(hash,hash_name, oList);
        find_hit_0  <hash_type>(hash,hash_name, oList);

        auto nList = oList;
        for (size_t v = 0; v < nList.size() / 2; v ++) {
            auto& next = nList[v];
#if KEY_INT
            next += nList.size() / 2 - v;
#elif KEY_CLA
            next.lScore += nList.size() / 2 - v;
#elif TKey != 4
            next[v % next.size()] += 1;
#else
            next = next.substr(0, next.size() - 1);
#endif
        }

        //shuffle(nList.begin(), nList.end());
        find_hit_50<hash_type>(hash, hash_name, nList);

        find_hit_50_erase<hash_type>(hash, hash_name, nList);
#if 1
        erase_50<hash_type>(hash, hash_name, nList);
        find_erase_50<hash_type>(hash, hash_name, oList);

        insert_find_erase<hash_type>(hash, hash_name, nList);
        erase_reinsert<hash_type>(hash, hash_name, oList);

        hash_iter<hash_type>(hash, hash_name);
#ifdef UF
        copy_clear <hash_type>(hash, hash_name);
        //hash_clear<hash_type>(hash, hash_name);
#endif
#endif
#endif

        func_size = func_index;
    }
}

constexpr static auto base1 = 300000000;
constexpr static auto base2 =      20000;
void reset_top3(std::map<std::string, int64_t>& top3, const std::multimap <int64_t, std::string>& once_score_hash)
{
    auto it0 = once_score_hash.begin();
    auto it1 = *(it0++);
    auto it2 = *(it0++);
    auto it3 = *(it0++);

    //the top 3 func map
    if (it1.first == it3.first) {
        top3[it1.second] += base1 / 3;
        top3[it2.second] += base1 / 3;
        top3[it3.second] += base1 / 3;
    } else if (it1.first == it2.first) {
        top3[it1.second] += base1 / 2;
        top3[it2.second] += base1 / 2;
        top3[it3.second] += 1;
    } else {
        top3[it1.second] += base1;
        if (it2.first == it3.first) {
            top3[it2.second] += base2 / 2;
            top3[it3.second] += base2 / 2;
        } else {
            top3[it2.second] += base2;
            top3[it3.second] += 1;
        }
    }
}

static void printResult()
{
    //total func hash time
    static std::map<std::string, std::map<std::string, int64_t>> func_hash_score;
//    static std::map<std::string, std::map<std::string, int64_t>> func_hash_score;
    static std::map<std::string, int64_t> top3;

    std::multimap<int64_t, std::string> once_score_hash;
    add_hash_func_time(func_hash_score, once_score_hash);
    if (once_score_hash.size() >= 3) {
        reset_top3(top3, once_score_hash);
    }

    constexpr int dis_input = 10;
    if (++test_case % dis_input != 0 && test_case % 7 != 0) {
        printf("=======================================================================\n\n");
        return ;
    }

    //print function rank
    std::multimap<int64_t, std::string> score_hash;
    printf("-------------------------------- function benchmark -----------------------------------------------\n");
    dump_all(func_hash_score, score_hash);

    //print top 3 rank
    if (top3.size() >= 3)
        puts("======== hash  top1   top2  top3 =======================");
    for (auto& v : top3)
        printf("%13s %4.1lf  %4.1lf %4d\n", v.first.data(), v.second / (double)(base1), (v.second / (base2 / 2) % 1000) / 2.0, (int)(v.second % (base2 / 2)));

    auto maxs = score_hash.rbegin()->first;
    //print hash rank
    puts("======== hash    score  weigh ==========================");
    for (auto& v : score_hash)
        printf("%13s  %4d     %3.1lf%%\n", v.second.data(), (int)(v.first / func_hash_score.size()), (v.first * 100.0 / maxs));

#if _WIN32
    Sleep(100*1);
#else
    usleep(1000*2000);
#endif
    printf("--------------------------------------------------------------------\n\n");
}

static int benchHashMap(int n)
{
    if (n < 10000)
        n = 123456;

    func_result.clear(); once_func_hash_time.clear();

    std::vector<keyType> vList;
    auto flag = buildTestData(n, vList);

#if ABSL_HASH && ABSL
    using ehash_func = absl::Hash<keyType>;
#elif WY_HASH && KEY_STR
    using ehash_func = WysHasher;
#elif AHASH_AHASH_H && KEY_STR
    using ehash_func = Ahash64er;
#elif KEY_INT && FIB_HASH > 0
    using ehash_func = Int64Hasher<keyType>;
#elif KEY_CLA
    using ehash_func = StuHasher;
#elif PHMAP_HASH
    using ehash_func = phmap::Hash<keyType>;
#elif HOOD_HASH
    using ehash_func = robin_hood::hash<keyType>;
#elif QCH && KEY_INT
    using ehash_func = qc::hash::RawMap<keyType, valueType>::hasher;
#else
    using ehash_func = std::hash<keyType>;
#endif

    {
        int64_t ts = getus(), sum = 0ul;
        for (auto& v : vList)
#if KEY_INT
            sum += (int)v;
#elif KEY_CLA
        sum += v.lScore;
#else
        sum += v.size();
#endif
        loop_vector_time = getus() - ts;
        printf("n = %d, keyType = %s, valueType = %s(%zd), loop_sum = %d us, sum = %d\n",
                n, sKeyType, sValueType, sizeof(valueType), (int)(loop_vector_time), (int)sum);
    }

    {
        func_first = (func_first + 3) % func_size + 1;
        func_last  = (func_first + 4) % func_size + 1;

        //shuffle(vList.begin(), vList.end());

#if ET > 2
        {  benOneHash<tsl::hopscotch_map   <keyType, valueType, ehash_func>>("hopsco", vList); }
#if X86_64 && __cplusplus >= 201402L
        {  benOneHash<ska::bytell_hash_map <keyType, valueType, ehash_func>>("sbyte", vList); }
#endif
        {  benOneHash<emlru_time::lru_cache<keyType, valueType, ehash_func>>("lru_time", vList); }
        {  benOneHash<emlru_size::lru_cache<keyType, valueType, ehash_func>>("lru_size", vList); }
#endif

        {  benOneHash<std::unordered_map<keyType, valueType, ehash_func>>   ("stl_hash", vList); }
#if ET > 1
        {  benOneHash<tsl::robin_map        <keyType, valueType, ehash_func>>("tslr", vList); }
        //{  benOneHash<emilib3::HashMap <keyType, valueType, ehash_func>>("emilib3", vList); }
        //{  benOneHash<emilib4::HashMap      <keyType, valueType, ehash_func>>("emilib4", vList); }

#if X86_64
        {  benOneHash<ska::flat_hash_map <keyType, valueType, ehash_func>>("skaf", vList); }
#if __cplusplus > 201402L || _MSVC_LANG >= 201402L
        {  benOneHash<hrd7::hash_map     <keyType, valueType, ehash_func>>("hrdset", vList); }
#endif
#endif
#endif

#ifdef SMAP
        {  benOneHash<std::map<keyType, valueType>>          ("stl_map", vList); }
//        {  benOneHash<std::flat_map<keyType, valueType>>     ("fmap", vList); }

#if __GNUC__ && __linux__
//        {  benOneHash<__gnu_pbds::gp_hash_table<keyType, valueType>>("gp_hash", vList) };
#endif

#if ET
        {  benOneHash<phmap::btree_map<keyType, valueType> >("btree", vList); }
#endif
#endif

#ifdef EM3
        {  benOneHash<emhash2::HashMap <keyType, valueType, ehash_func>>("emhash2", vList); }
        {  benOneHash<emhash4::HashMap <keyType, valueType, ehash_func>>("emhash4", vList); }
        {  benOneHash<emhash3::HashMap <keyType, valueType, ehash_func>>("emhash3", vList); }
#endif
#if ABSL
        {  benOneHash<absl::flat_hash_map <keyType, valueType, ehash_func>>("abslf", vList); }
#endif

#if FOLLY
        {  benOneHash<folly::F14ValueMap<keyType, valueType, ehash_func>>("f14_value", vList); }
        {  benOneHash<folly::F14VectorMap<keyType, valueType, ehash_func>>("f14_vector", vList); }
#endif

#if CUCKOO_HASHMAP
        {  benOneHash<libcuckoo::cuckoohash_map <keyType, valueType, ehash_func>>("cuckoo", vList); }
#endif

#if CXX20
        {  benOneHash<jg::dense_hash_map <keyType, valueType, ehash_func>>("jg_dense", vList); }
        {  benOneHash<rigtorp::HashMap <keyType, valueType, ehash_func>>("rigtorp", vList); }
        {  benOneHash<ankerl::unordered_dense::map <keyType, valueType, ehash_func>>("martind", vList); }
#endif

#if QC_HASH && KEY_INT
        {  benOneHash<qc::hash::RawMap<keyType, valueType, ehash_func>>("qchash", vList); }
#endif
#if FPH_HASH
        {  benOneHash<fph::DynamicFphMap<keyType, valueType, fph::MixSeedHash<keyType>>>("fph", vList); }
#endif

#if X86
        //            {  benOneHash<emilib1::HashMap      <keyType, valueType, ehash_func>>("emilib1", vList); }
        {  benOneHash<emilib2::HashMap      <keyType, valueType, ehash_func>>("emilib2", vList); }
        {  benOneHash<emilib3::HashMap      <keyType, valueType, ehash_func>>("emilib3", vList); }
        {  benOneHash<emilib::HashMap       <keyType, valueType, ehash_func>>("emilib1", vList); }
#endif
        {  benOneHash<emhash7::HashMap <keyType, valueType, ehash_func>>("emhash7", vList); }
        {  benOneHash<emhash8::HashMap <keyType, valueType, ehash_func>>("emhash8", vList); }
        {  benOneHash<emhash6::HashMap <keyType, valueType, ehash_func>>("emhash6", vList); }
        {  benOneHash<emhash5::HashMap <keyType, valueType, ehash_func>>("emhash5", vList); }
#if ET
        {  benOneHash<phmap::flat_hash_map <keyType, valueType, ehash_func>>("phmap", vList); }
        {  benOneHash<robin_hood::unordered_map <keyType, valueType, ehash_func>>("martinf", vList); }
        //{  benOneHash<simd_hash_map<keyType, valueType, ehash_func>>("simd_hash", vList); }

        //{  benOneHash<zedland::hashmap <keyType, valueType, ehash_func>>("zhashmap", vList); }

#if FHT_HMAP
        {  benOneHash<fht_table <keyType, valueType, ehash_func>>("fht", vList); }
#endif
#endif
    }

    assert(n == vList.size());
    const auto pow2 = 2u << ilog(n, 2);

    constexpr uint64_t kv = sizeof(std::pair<keyType, valueType>);// sizeof(keyType) + sizeof(valueType) + (eq ? 0 : 4);
    auto memory1 = 8 * pow2 + kv * n; //emhash8 table
    auto memory2 = (1 + kv) * pow2;   //flat hash map
    auto memoryr = (8 * 4 + 8 + kv + 8) * n; //std::map
    auto memoryu = 8 * pow2 + (8 + 8 + 8 + kv) * n; //std::unordered_map

    printf("\n %d ======== n = %d, load_factor = %.3lf(emh8/flat = %.2lf/%.2lf, smap/umap = %.2lf/%.2lf MB), data_type = %d ========\n",
            test_case + 1, n, 1.0 * n / pow2, 1.0 * memory1 / (1 << 20) , 1.0 * memory2 / (1 << 20),
            1.0 * memoryr / (1 << 20), 1.0 * memoryu / (1 << 20), flag);

    printResult();
    return test_case;
}

static void testHashInt(int loops = 500000009)
{
    printf("%s loops = %d\n", __FUNCTION__, loops);
    auto ts = getus();
    long sum = ts;
    auto r  =  ts;

#ifdef PHMAP_VERSION_MAJOR
    ts = getus(); sum = 0;
    for (int i = 0; i < loops; i++)
        sum += phmap::phmap_mix<8>()(i + r);
    printf("phmap hash = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);
#endif

#if ABSL_HASH && ABSL
    ts = getus(); sum = r;
    for (int i = 0; i < loops; i++)
        sum += absl::Hash<uint64_t>()(i + r);
    printf("absl hash  = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);
#endif

#ifdef WYHASH_LITTLE_ENDIAN
    ts = getus(); sum = r;
    auto seed = randomseed();
    for (int i = 0; i < loops; i++)
        sum += wyhash64(i + r, seed);
    printf("wyhash64   = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);
#endif

    ts = getus(); sum = r;
    for (int i = 1; i < loops; i++)
        sum += (int)sum + i;
    printf("sum  add   = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);

#ifdef ROBIN_HOOD_H_INCLUDED
    ts = getus(); sum = r;
    for (int i = 0; i < loops; i++)
        sum += robin_hood::hash_int(i + r);
    printf("martinus hash= %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);
#endif

    ts = getus(); sum = r;
    for (int i = 0; i < loops; i++)
        sum += std::hash<uint64_t>()(i + r);
    printf("std hash   = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);

    ts = getus(); sum = r;
    for (int i = 0; i < loops; i++)
        sum += hashfib(i + r);
    printf("hashfib    = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);

    ts = getus(); sum = r;
    for (int i = 0; i < loops; i++)
        sum += hash_mur3(i + r);
    printf("hash_mur3  = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);

    ts = getus(); sum = r;
    for (int i = 0; i < loops; i++)
        sum += hashmix(i + r);
    printf("hashmix    = %4d ms [%ld]\n", (int)(getus() - ts) / 1000, sum);

    ts = getus(); sum = r;
    for (int i = 0; i < loops; i++)
        sum += rrxmrrxmsx_0(i + r);
    printf("rrxmrrxmsx_0= %3d ms [%ld]\n\n", (int)(getus() - ts) / 1000, sum);

#if 0
    const int buff_size = 1024*1024 * 16;
    const int pack_size = 64;
    auto buffer = new char[buff_size * pack_size];
    memset(buffer, 0, buff_size * pack_size);

    for (int i = 0; i < 4; i++) {
        ts = getus();
        memset(buffer, 0, buff_size * pack_size);
        printf("memset   = %4d ms\n", (int)(getus() - ts) / 1000);

        ts = getus();
        for (uint32_t bi = 0; bi < buff_size; bi++)
           *(int*)(buffer + (bi * pack_size)) = 0;
        printf("loops   = %4d ms\n\n", (int)(getus() - ts) / 1000);
    }
    delete [] buffer;
#endif
}

#if 0
static int test_lru(int n)
{
#if ET
    emlru_size::lru_cache<uint64_t, int> elru(1 << 10, 1<<20);
    Sfc4 srng(n);
    auto ts = getus();
    for (int i = 0; i < n ; i++) {
        elru.emplace(i, i);
    }
    printf("n = %d, hsize = %zd, time use = %d ms\n", n, elru.size(), (int)(getus() - ts) / 1000);
#endif
    return 0;
}
#endif

int main(int argc, char* argv[])
{
#if WYHASH_LITTLE_ENDIAN && STR_VIEW
    //find_test();
#endif
    auto start = getus();
//    test_lru(100'000'000);
    testHashInt(2e7+8);

#ifdef AHASH_AHASH_H
    printf("ahash_version = %s\n", ahash_version());
#endif

    printInfo(nullptr);

    int run_type = 0;
    int rnd = randomseed();
    auto maxc = 500;
    int minn = (1000 * 100 * 8) / sizeof(keyType) + 10000;
    int maxn = 100*minn;
    if (TKey < 3)
        minn *= 2;

    const int type_size = (sizeof(keyType) + sizeof(valueType) + 4);
    if (maxn > (1 << 30) / type_size)
        maxn = (1 << 30) / type_size;

    float load_factor = 0.0945f;
    printf("./ebench maxn = %d c(0-1000) f(0-100) d[2-9 mpatseblku] a(0-3) b t(n %dkB - %dMB)\n",
            (int)maxn, minn*type_size >> 10, maxn*type_size >> 20);

    for (int i = 1; i < argc; i++) {
        const auto cmd = argv[i][0];
        const auto value = atoi(&argv[i][0] + 1);

        if (isdigit(cmd))
            maxn = atoi(argv[i]) + 1000;
        else if (cmd == 'f' && value > 0)
            load_factor = atof(&argv[i][0] + 1) / 100.0f;
        else if (cmd == 'c' && value > 0)
            maxc = value;
        else if (cmd == 'a')
            run_type = value;
        else if (cmd == 'r' && value > 0)
            rnd = value;
        else if (cmd == 'n')
            minn = value;
        else if (cmd == 'm')
            maxn = value;
        else if (cmd == 'd') {
        for (char c = argv[i][1], j = 1; c != '\0'; c = argv[i][++j]) {
            if (c >= '5' && c <= '9') {
                std::string hash_name("emhash");
                hash_name += c;
                if (maps.find(hash_name) != maps.end())
                    maps.erase(hash_name);
                else
                    maps[hash_name] = hash_name;
            }
            else if (c == 'm') {
                maps.erase("martinf");
                maps.erase("martind");
            } else if (c == 'p')
                maps.erase("phmap");
            else if (c == 't')
                maps.erase("tslr");
            else if (c == 's')
                maps.erase("skaf");
            else if (c == 'a')
                maps.erase("abslf");
            else if (c == 'v')
                maps.erase("f14_vector");
            else if (c == 'h')
                maps.erase("hrdset");
            else if (c == 'j')
                maps.emplace("jg_dense", "jg_dense");
            else if (c == 'r')
                maps.emplace("rigtorp", "rigtorp");
            else if (c == 'q')
                maps.emplace("qchash",  "qc-hash");
            else if (c == 'f')
                maps.emplace("fph", "fph-table");

            else if (c >= '1' && c <= '3') {
                const std::string emistr = std::string("emilib") + c;
                if (maps.find(emistr) != maps.end()) maps.erase(emistr);
                else maps.emplace(emistr, emistr);
            }
            else if (c == 'l') {
                maps.emplace("lru_size", "lru_size");
                maps.emplace("lru_time", "lru_time");
            }
            else if (c == 'k')
                maps.emplace("ktprime", "ktprime");
            else if (c == 'b') {
                maps.emplace("btree", "btree_map");
                maps.emplace("stl_map", "stl_map");
                maps.emplace("fmap", "flat_map");
            } else if (c == 'u')
                maps.emplace("stl_hash", "unordered_map");
        }}
    }

    Sfc4 srng(rnd);
    for (auto& m : maps)
        printf("  %s\n", m.second.data());
    putchar('\n');

    int n = (srng() % (2*minn)) + minn;
    while (true) {
        if (run_type == 2) {
            printf(">>");
#if _WIN32
            if (scanf_s("%d", &n, sizeof(n)) == 0)
#else
            if (scanf("%d", &n) == 0)
#endif
                break;
            if (n <= 1)
                run_type = 0;
            else if (n < -minn) {
                run_type = 1;
                n = -n;
            }
        } else if (run_type == 1) {
            n = (srng() % (maxn - minn)) + minn;
        } else {
            n += n / 15;
            if (n > maxn)
                n = (srng() % (maxn - minn)) + minn;
        }

        auto pow2 = 2 << ilog(n, 2);
        hlf = 1.0 * n / pow2;
        if (load_factor > 0.2 && load_factor < 1) {
            n = int(pow2 * load_factor) - (1 << 10) + (srng()) % (1 << 8);
            hlf = 1.0 * n / pow2;
        }
        if (n < 1000 || n > 1234567890)
            n = minn + srng() % minn;

        int tc = benchHashMap(n);
        if (tc >= maxc)
            break;
    }

    printf("total time = %.3lf s", (getus() - start) / 1000000.0);
    return 0;
}

