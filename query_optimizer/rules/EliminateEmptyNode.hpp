/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 **/

#ifndef QUICKSTEP_QUERY_OPTIMIZER_RULES_ELIMINATE_EMPTY_NODE_HPP_
#define QUICKSTEP_QUERY_OPTIMIZER_RULES_ELIMINATE_EMPTY_NODE_HPP_

#include <string>

#include "query_optimizer/physical/Physical.hpp"
#include "query_optimizer/rules/Rule.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

class CatalogDatabase;

namespace optimizer {

/** \addtogroup OptimizerRules
 *  @{
 */

/**
 * @brief Rule that applies to a physical plan to eliminate a node with an empty
 *        TableReference to a Selection on a temp table.
 */
class EliminateEmptyNode : public Rule<physical::Physical> {
 public:
  /**
   * @brief Constructor.
   */
  explicit EliminateEmptyNode(CatalogDatabase *catalog_database)
      : catalog_database_(catalog_database) {}

  ~EliminateEmptyNode() override {}

  std::string getName() const override {
    return "EliminateEmptyNode";
  }

  physical::PhysicalPtr apply(const physical::PhysicalPtr &input) override;

 private:
  CatalogDatabase *catalog_database_;

  DISALLOW_COPY_AND_ASSIGN(EliminateEmptyNode);
};

/** @} */

}  // namespace optimizer
}  // namespace quickstep

#endif  // QUICKSTEP_QUERY_OPTIMIZER_RULES_ELIMINATE_EMPTY_NODE_HPP_
