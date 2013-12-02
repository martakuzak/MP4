#ifndef ANALYZER_H
#define ANALYZER_H
#include <QString>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QVariant>
#include <qDebug>
#include "treemodel.h"
#include "treeitem.h"


class TreeItem;
class TreeModel;
/*!
 * \brief The Analyzer class - provides with tools to analyze MP4 file.
 */
class Analyzer
{
public:
    Analyzer();
    /*!
     * \brief Analyzer - constructor
     * \param fileName name of the file to be analyzed
     */
    Analyzer(const QString& fileName);
    ~Analyzer();
    /*!
     * \brief setData adds children to the parent.
     * \param parent parent of the tree fragment that children are to be analyzed.
     */
    void setData(TreeItem* parent, QHash<long,TreeItem*>* items);
    /*!
     * \brief valueOfGroupOfBytes takes a given sequence of bytes and converts them into unsigned long int value
     * \param length number of bytes in the sequence
     * \param offset offset of the sequence in the file
     * \return value of byte sequence
     */
    unsigned long int valueOfGroupOfBytes(const int & length, const unsigned long int& offset = 0);
    /*!
     * \brief valueOfGroupOfBits takes a given sequence of bits and converts them into unsigned long int value
     * \param length number of bits in the sequence
     * \param offset offset of the sequnce in the file
     * \return value of bit sequence
     */
    unsigned long int valueOfGroupOfBits(const int & length, const unsigned long int& offset);
    /*!
     * \brief toQString
     *  converts unsigned int to QString
     * \param num value to be converted
     * \param bytes number of bytes the unsigned int has been created from
     * \return converted QString object
     */
    QString toQString(unsigned int num,int bytes);
    /*!
     * \brief set
     * private method is called inside setData method. It adds children to the parent.
     * \param arr QByteArray of analyzed bytes
     * \param parent parent of the tree fragment that children are to be analyzed.
     * \param off offset
     */
private:
    /*!
     * \brief setData the method is calls inside public setData method. It analyzes mp4 file by finding boxes, creating TreeItem objects
     * for each box and adding them to their parents.
     * \param parent parent of the tree fragment that children are to be analyzed
     * \param items hashmap of TreeItem pointers
     * \param off offset of the analyzed box
     * \param maxOff max offset possible of the parent analyzed box
     */
    void setData(TreeItem* &parent, QHash<long,TreeItem*>* items, const unsigned long int &off, unsigned long int maxOff = 0L);
    /*!
     * \brief fileName
     *  name of the analyzed file
     */
    QString fileName;
    /*!
     * \brief tempArray
     */
    QFile* file;
    /*!
     * \brief arraySize
     */
    unsigned long int fileSize;

};


#endif // ANALYZER_H
