/**
 * <p>Title: Example to show data being exchanged between Simulink and JADE agents.</p>
 *
 * <p>Description: This JADE agent is used to demonstrate how one can be set up in order
 * to receive data from Simulink via the Agent Environment(that is the Agent Coordinator
 * and AgentServer).  It also shows the exchange of data between agents and then how
 * the data is finally returned back to Simulink.</p>
 *
 * <p>Copyright: Copyright (c) 2009</p>
 *
 * @author Charles Robinson
 * @version 1.0
 */
package example;

import macsimjx.*;

import jade.lang.acl.ACLMessage;
import jade.domain.FIPAException;
import jade.domain.DFService;
import jade.core.behaviours.CyclicBehaviour;
import jade.core.Agent;
import jade.core.AID;


public class SimpleDifferenceAgent extends UsefulAgentMethods {
    Agent thisAgent = (Agent)this;
    int agentNumber = 0;

    /*
     * These determine which elements of the input data that this agent
     * is interested in, and which element of the out going data it is
     * changing.
     */
    int[] inputPortsOfInterest = {1}; // I.e. Second to top signal input to MACSim block.
    int[] outputPorts = {1}; // Set which ports in simulink data is shown on.


    // Set to true for helpful output.
    boolean debug = false;

    // Keep track of number of information agents.
    private int agentsSubscribed = 0;
    private int agentsLeftToRespond = 0;

    boolean firstRun = true;
    boolean dataUpdated = false;
    AID[] agentIDs = null;
    AID agentID = null;
    AID AgentCoordinatorID = null;

    TimeStepData tsd = new TimeStepData();

    double signal2 = 0;
    double difference=0;


    public void setup() {
        addBehaviour(new filterBehaviour());

        /*
         * Register agent with directory facilitator of JADE along with the
         * services it provides (in this case, arithmetic and generic agent services).
         * NB - To change properties after registering use the JADE 'modify' method.
         */
        String[] services = {"arithmetic", "Agent"};
        registerAgent(thisAgent, services, services);


        // Get agent number from argument provided by instantiator of this agent.
        Object[] args = getArguments();
        if (args != null && args.length > 0) {
            String firstArg = args[0].toString();
            agentNumber = new Integer(firstArg).intValue();

        } else {
            // Terminate agent.
            System.out.println("No agent id");
            doDelete();
        }

        try {
            // Locate data provider.
            AgentCoordinatorID = getAgentIDsOfService(thisAgent,
                    "InputsUpdate")[0];

            // Find agents that are interested in this agent's data.
            agentIDs = getAgentIDsOfService(thisAgent, "arithmetic");

            /*
             * N.B. If environment is dynamic would need to perform these
             * searches either more than once to check for new agents, or
             * implement some service subscription method to receive a message
             * when new agents enter environment.
             */

        } catch (Exception e) {
            System.out.println("Error finding service: " + e);
        }

        agentsSubscribed = countSubscribingAgents(thisAgent, "arithmetic");

        if (debug)
            System.out.println("agentsSubscribed to arithmetic service:"
                               + agentsSubscribed);
        
        agentsLeftToRespond = agentsSubscribed - 1;


    }

    class filterBehaviour extends CyclicBehaviour {
        public void action() {

            TimeStepData tsd = new TimeStepData();
            double[] dataArray;
            int length;

            ACLMessage msg = receive();

            if (msg != null) {
                String message = msg.getConversationId();

                // If new data from AgentCoordinator (ie Simulink).
                if (message.equals("UpdateData")) {

                    try {
                        tsd = (TimeStepData) msg.getContentObject();
                    } catch (Exception e) {
                        System.out.println("Exception with content object" + e);
                    }

                    // Extract data from incoming array.
                    length = tsd.getData().length;
                    dataArray = new double[length];
                    for (int i = 0; i < length; i++)
                        dataArray[i] = tsd.getData()[i];

                    if (debug) {
                        System.out.println("(Debug)Incoming data: ");
                        for (int j = 0; j < length; j++) {
                            System.out.print(j + ": " + dataArray[j] + " ");
                        }
                        System.out.printf("\n");
                    }
                    
/**  Agent particular aspects begin here.     *****************/

                    // Extract the relevant data.
                    signal2 = dataArray[inputPortsOfInterest[0]];                 

                    /* Perform here any calculations required before using data from
                     * other agents.
                     */   
                    
/** Block ends here ******************************************************************/
                    if (debug) {
                        System.out.println(getLocalName() +
                                           " awaiting info from "
                                           + agentsLeftToRespond + " agent(s)");
                    }
                    dataUpdated = true;

                    /*
                     * Pass information about the new data to the 
                     * other agents.
                     */
                    if (agentsSubscribed > 1) {
                        try {
                        	
/** Set information in dataStructure to be passed to other agents ******************/
                        	
                            double [] dataToShare = {signal2};
                            int [] elementToChange ={0};
                            TimeStepData tsdInner= new TimeStepData();

                            // Populate data structure with required data to exchange.
                            tsdInner.setData(dataToShare);
                            tsdInner.setElementsToChange(elementToChange);
                        



                            // Send information off to other agents.
                            for (int i = 0; i < agentIDs.length; i++) {
                                if (!agentIDs[i].getLocalName().equals(
                                        thisAgent.getLocalName())) {
                                    sendObject(agentIDs[i], "agentData",
                                    		tsdInner);
                                }
                            }
/** Block ends here ******************************************************************/                            
                        } catch (Exception e) {
                            System.out.println("Exception: " + e);
                        }
                    }

                    if (agentsLeftToRespond == 0) {
                    	finishCalculationsThenSend();
                    }
                }
                
                // Additional information from another agent.
                if (message.equals("agentData")
                    && !msg.getSender().getLocalName().equals(
                            thisAgent.getLocalName())) {
                    try {
                        tsd = (TimeStepData) msg.getContentObject();
                    } catch (Exception e) {
                        System.out.println("Exception getting content object: "
                                           + e);
                    }

                    length = tsd.getData().length;
                    dataArray = new double[length];
                    for (int i = 0; i < length; i++)
                        dataArray[i] = tsd.getData()[i];
                    
/** Agent specific task inside this block *******************************************/  
                    int [] elementsToUse = tsd.getElementsToChange();
                    double signal1 = dataArray[elementsToUse[0]];

                   // Perform calculations with data from other agents.
                    
                   //In this case find the difference of the both signals.
                    difference = signal1- signal2;

/** Block ends here ******************************************************************/                    

                    agentsLeftToRespond--;
                    if (debug)
                    System.out.println(getLocalName() + " recieved info "
                                       + " awaiting "
                                       + agentsLeftToRespond + " more.");

                    if (agentsLeftToRespond == 0 && dataUpdated) {
                        finishCalculationsThenSend();
                    }
                }

                if (message.equals("DataAmended")) {
                    if (debug)
                        System.out.println("Agent " + agentNumber + " finished.");

                    replyToAgent(msg.getSender(), "ProcessingComplete");
                }

                if (message.equals("Shutting Down")) {
                    takeDown(msg.getSender());
                }
            } else {
                block();
            }
        }
    }


    /**
     * Finalise calculations and return to AgentCoordinator and Simulink.
     */
    public void finishCalculationsThenSend() {

/** Agent specific task inside this block *******************************************/  
    	// Carry out any final calculation before returning back to Simulink and 
    	// specified port.

        double[] dataOut = new double[outputPorts.length];
        dataOut[0] = difference;


/** Block ends here ******************************************************************/  
        
        
        tsd.setData(dataOut);
        tsd.setElementsToChange(outputPorts);

        // Send modified data back to Simulink.
        ACLMessage reply = new ACLMessage(ACLMessage.INFORM);
        reply.setConversationId("ProcessedData");

        try {
            reply.setContentObject(tsd);
        } catch (Exception e) {
            System.out.println("Exception setting tsd: " + e);
        }

        if (debug)
            System.out.println(getLocalName() + " finished, sending data to "
                               + AgentCoordinatorID.getLocalName());
        reply.addReceiver(AgentCoordinatorID);
        send(reply);
        agentsLeftToRespond = agentsSubscribed - 1;
        dataUpdated = false;
    }
    

    /**
     * Terminate agent.
     *
     * @param senderAID AID
     */
    protected void takeDown(AID senderAID) {
        try {
            System.out.println("Deregistering and closing " + thisAgent);
            DFService.deregister(thisAgent);
        } catch (FIPAException fe) {
            System.out.println("Problem deregistering " + fe);
        }
        if (senderAID != null)
            contactAgent(senderAID, "Agent Deregistered");

        doDelete();
    }
}
