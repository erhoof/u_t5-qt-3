#ifndef HARDDRIVEINFO_H
#define HARDDRIVEINFO_H

enum class Direction {
    In, Out
};

enum class HardDriveStatus {
    Read, Write, Free
};

struct HardDriveInfo
{
    float m_accessTime = 1;
    float m_rotationDelay = 0.5;
    float m_transferSpeed = 10.0;

    int m_cylinders = 10;
    int m_sectors = 30;
    int m_heads = 1;
};

struct HardDrivePointer
{
    int cylinder = 0;
    int head = 0;
    int sector = 0;
};

#endif // HARDDRIVEINFO_H
