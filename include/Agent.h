#ifndef AGENT_H_
#define AGENT_H_

#include "Session.h"
#include <vector>

class Agent{
public:
    Agent(); // DO NOT CHANGE!
    virtual void act(Session& session)=0; // DO NOT CHANGE!
    virtual ~Agent(){}; // Destructor
  
    virtual Agent* clone() const=0;
    virtual char getType() const=0;
    virtual int getNode() const=0;
};

class ContactTracer: public Agent{
public:
    ContactTracer(); // DO NOT CHANGE!
    ContactTracer(const ContactTracer &contactTracer); // Copy-Constructor
    virtual ~ContactTracer(); // Destructor

    ContactTracer* clone() const;
    int getNode() const {return -1;};
    char getType() const;
    virtual void act(Session& session); // DO NOT CHANGE!
    void removeAllEdges(Session& session, int node);
    int dequeueInfected(Session& session);
};


class Virus: public Agent{
public:
    Virus(int nodeInd); // DO NOT CHANGE!
    Virus(const Virus &other); // Copy-Constructor
    Virus(Virus&& other); // Move-Constructor
    virtual ~Virus(); // Destructor

    char getType() const;
    virtual Virus* clone() const; // for copying
    virtual void act(Session& session); // DO NOT CHANGE!
    void infectNode(Session& session);
    void deactivate(Session& session); // set Virus as not active
    int getNode() const; // return nodeInd

private:
    const int nodeInd; // DO NOT CHANGE!
    bool is_active=true; // Whether Virus.act() should run
    int findNextVictim(Session& session) const; // get next node to spread to
    void occupy(Session& session, int node); // spread to node
};

#endif