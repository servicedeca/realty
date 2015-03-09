<div class="container fin">

  <div id="complex-plan">
    <div class="col-xs-10 col-xs-offset-1 tab-menu zero-padding">
      <div class="col-xs-8 zero-padding">
        <div class="col-xs-4 tab-menu-active">
          <?php print t('overall plan');?>
        </div>
      </div>
    </div>
    <div class="col-xs-8 right-part-complex zero-padding">
      <?php if($homes):?>
        <?php foreach($homes as $home):?>
          <?php print $home['number']?>
        <?php endforeach?>
      <?php endif;?>
      <?php if($complex_plan):?>
        <?php print $complex_plan;?>
      <?php endif;?>
    </div>
    <div class="col-xs-4 left-part-complex zero-padding">
      <div class="vertical">
        <?php print $deadline_description;?>
      </div>
    </div>
  </div>

  <?php if($homes):?>
    <?php foreach($homes as $home):?>
    <div id="home-<?php print $home['tid']?>-plan" class="plan-home-section">
      <div class="col-xs-10 col-xs-offset-1 tab-menu zero-padding">
        <div class="col-xs-8 zero-padding">
          <div class="col-xs-4 tab-menu-passive over-plan">
            <?php print t('overall plan');?>
          </div>
          <div class="col-xs-4 tab-menu-active">
            <a href="#href" class="" title="Выберите дом">
              <?php print t('Sections');?>
            </a>
          </div>
        </div>
      </div>
      <div class="col-xs-8 right-part-complex zero-padding">
        <?php print $home['plan'];?>
        <?php foreach($sections as $section):?>
          <?php if($section['home_tid'] == $home['tid']):?>
            <?php print $section['section'];?>
          <?php endif;?>
        <?php endforeach?>
      </div>
      <div class="col-xs-4 left-part-complex zero-padding">
        <div class="vertical">
          <?php print $home['description'];?>
        </div>
      </div>
    </div>
    <?php endforeach;?>
  <?php endif;?>

  <?php foreach($sections as $section):?>
    <?php if(isset($section['plan'])):?>
      <div id="home-<?php print $home['tid']?>-<?php print $section['number'].'-'.$section['floor']?>" class="plan-home-section-floor">
        <div class="col-xs-10 col-xs-offset-1 tab-menu zero-padding">
          <div class="col-xs-8 zero-padding">
            <div class="col-xs-4 tab-menu-passive over-plan">
              <?php print t('overall plan');?>
            </div>
            <div class="col-xs-4 tab-menu-passive">
              <a id="back-<?php print $home['tid']?>" href="#" class="plan-complex-home" title="Выберите дом">
                <?php print t('Sections');?>
              </a>
            </div>
            <div class="col-xs-4 tab-menu-active">
              <a href="#" class="" title="Выберите дом">
                <?php print t('Floors');?>
              </a>
            </div>
          </div>
        </div>
        <div class="col-xs-8 zero-padding floor-image-block">
          <?php print $section['plan']?>
        </div>
        <div class="col-xs-4 left-part-complex zero-padding display-table">
          <div class="vertical">
              <ul id="floorTab" role="tablist">
                <?php foreach($sections as $floor):?>
                  <?php if($section['number'] == $floor['number']):?>
                    <li>
                      <?php print $floor['floor'];?>
                    </li>
                  <?php endif;?>
                <?php endforeach?>
              </ul>
          </div>
        </div>
      </div>
    <?php endif;?>
  <?php endforeach;?>


</div>